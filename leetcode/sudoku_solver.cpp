/*

   Sudoku Solver

   Write a program to solve a Sudoku puzzle by filling the empty cells.

   Empty cells are indicated by the character '.'.

   You may assume that there will be only one unique solution.

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // box means 3 x 3 grids, its id is from 0...8, row first...
    inline int getBoxId(int i, int j)
    {
        return (i / 3) * 3 + j / 3; // return 0...8
    }

    bool dfs(vector<vector<char>> &board, vector<vector<bool>> &canUseRow,
             vector<vector<bool>> &canUseCol,
             vector<vector<bool>> &canUseBox)
    {
        // traverse each grid
        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board[0].size(); j++) {
                if (board[i][j] == '.') { // '.', need to fill
                    int boxId = getBoxId(i, j);
                    for (int k = 0; k < 9; k++) {
                        if (canUseRow[i][k] && canUseCol[j][k]
                                && canUseBox[boxId][k]) {
                            board[i][j] = k + '1';
                            canUseRow[i][k] = false;
                            canUseCol[j][k] = false;
                            canUseBox[boxId][k] = false;

                            if (dfs(board, canUseRow, canUseCol, canUseBox))
                                return true;

                            // backtrack
                            canUseRow[i][k] = true;
                            canUseCol[j][k] = true;
                            canUseBox[boxId][k] = true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char> > &board)
    {
        vector<vector<bool>> canUseRow(9, vector<bool>(9, true));
        vector<vector<bool>> canUseCol(9, vector<bool>(9, true));
        vector<vector<bool>> canUseBox(9, vector<bool>(9, true));

        // initialization vector table
        for (size_t i = 0; i < board.size(); i++) {
            for (size_t j = 0; j < board[0].size(); j++) {
                if (board[i][j] != '.') { // number, no need to fill
                    int boxId = getBoxId(i, j);
                    int num = board[i][j] - '1';
                    canUseRow[i][num] = false;
                    canUseCol[j][num] = false;
                    canUseBox[boxId][num] = false;
                }
            }
        }

        dfs(board, canUseRow, canUseCol, canUseBox);
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<vector<char>> v1 = {
        { '5', '3', '.', '.', '7', '.', '.', '.', '.' },
        { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
        { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
        { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
        { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
        { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
        { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
        { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
        { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
    };

    sol.solveSudoku(v1);

    for (auto &row : v1) {
        for (auto c : row) {
            cout << c << ends;
        }
        cout << endl;
    }

    return 0;
}
