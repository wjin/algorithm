/*

 Valid Sudoku

 Determine if a Sudoku is valid。

 The Sudoku board could be partially filled, where empty cells are filled with the character '.'.

 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isValid(char ch, vector<bool> &used)
    {
        if (ch == '.')
            return true;
        if (used[ch - '1'])
            return false;
        used[ch - '1'] = true; // not '.' and non use, use it
        return true;
    }

    bool isValidSudoku(vector<vector<char>> &board)
    {
        const int len = 9; // board size, must be 9

        vector<bool> used(len, false); // record whether a number is used.

        // check each row and column
        for (int i = 0; i < len; i++) {
            fill(used.begin(), used.end(), 0);
            for (int j = 0; j < len; j++) { // check row
                if (!isValid(board[i][j], used))
                    return false;
            }

            fill(used.begin(), used.end(), 0);
            for (int j = 0; j < len; j++) { // check column
                if (!isValid(board[j][i], used))
                    return false;
            }
        }

        // check 3x3 sub boxes of the grid
        // row and col are coefficient
        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {

                fill(used.begin(), used.end(), 0);
                for (int i = row * 3; i < row * 3 + 3; i++) {
                    for (int j = col * 3; j < col * 3 + 3; j++) {
                        if (!isValid(board[i][j], used))
                            return false;
                    }
                }
            }
        }

        return true; // success
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

    vector<vector<char>> v2 = {
        { '5', '3', '.', '.', '3', '.', '.', '.', '.' },
        { '6', '.', '.', '1', '9', '5', '.', '.', '.' },
        { '.', '9', '8', '.', '.', '.', '.', '6', '.' },
        { '8', '.', '.', '.', '6', '.', '.', '.', '3' },
        { '4', '.', '.', '8', '.', '3', '.', '.', '1' },
        { '7', '.', '.', '.', '2', '.', '.', '.', '6' },
        { '.', '6', '.', '.', '.', '.', '2', '8', '.' },
        { '.', '.', '.', '4', '1', '9', '.', '.', '5' },
        { '.', '.', '.', '.', '8', '.', '.', '7', '9' }
    };

    cout << sol.isValidSudoku(v1) << endl;
    cout << sol.isValidSudoku(v2) << endl;

    return 0;
}
