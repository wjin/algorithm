/*

 Word Search

 Given a 2D board and a word, find if the word exists in the grid.

 The word can be constructed from letters of sequentially adjacent cell,
 where "adjacent" cells are those horizontally or vertically neighboring.
 The same letter cell may not be used more than once.

 For example,
 Given board =

 [
 ["ABCE"],
 ["SFCS"],
 ["ADEE"]
 ]
 word = "ABCCED", -> returns true,
 word = "SEE", -> returns true,
 word = "ABCB", -> returns false.

 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
private:
    int direction[4][2];
public:
    void dfs(vector<vector<char>> &board, string &word,
             vector<vector<bool>> &canUse, int x, int y, int dep, int maxDep,
             bool &flag)
    {
        if (flag)
            return;

        if (dep == maxDep) {
            flag = true;
            return;
        }

        for (int i = 0; i < 4; i++) {
            int _x = x + direction[i][0];
            int _y = y + direction[i][1];

            if (_x >= 0 && _x < board.size() && _y >= 0 && _y < board[0].size()
                    && canUse[_x][_y] && board[_x][_y] == word[dep]) {
                canUse[_x][_y] = false;
                dfs(board, word, canUse, _x, _y, dep + 1, maxDep, flag);
                canUse[_x][_y] = true;
            }
        }
    }

    bool exist(vector<vector<char>> &board, string word)
    {
        int row = board.size(), col = board[0].size();
        int word_len = word.length();

        vector<vector<bool>> canUse(row, vector<bool>(col, true));

        // initialization direction
        direction[0][0] = 1;
        direction[0][1] = 0;  // x + 1
        direction[1][0] = -1;
        direction[1][1] = 0;  // x - 1
        direction[2][0] = 0;
        direction[2][1] = 1;  // y + 1
        direction[3][0] = 0;
        direction[3][1] = -1; // y - 1

        // find the first match char and then dfs search
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (word[0] == board[i][j]) {
                    canUse[i][j] = false;
                    bool flag = false;
                    dfs(board, word, canUse, i, j, 1, word_len, flag);
                    if (flag)
                        return true;
                    canUse[i][j] = true;
                }
            }
        }
        return false;
    }
};

int main(int argc, char *argv[])
{
    vector<vector<char>> board = { { 'A', 'B', 'C', 'E' },
        { 'S', 'F', 'C', 'S' }, { 'A', 'D', 'E', 'E' }
    };

    string word1("ABCCED"); // true
    string word2("SEE"); // true
    string word3("ABCB"); // false

    Solution sol;

    cout << sol.exist(board, word1) << endl;
    cout << sol.exist(board, word2) << endl;
    cout << sol.exist(board, word3) << endl;

    return 0;
}
