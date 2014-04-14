/*

 Surrounded Regions

 Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

 A region is captured by flipping all 'O's into 'X's in that surrounded region .


 For example,

 X X X X
 X O O X
 X X O X
 X O X X

 After running your function, the board should be:

 X X X X
 X X X X
 X X X X
 X O X X

 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    // dfs, cannot pass OJ
    bool isWrapped(int i, int j, vector<vector<char>> &board,
                   vector<vector<bool>> &tag)
    {
        if (board[i][j] == 'X' || tag[i][j] == true) {
            return true;
        } else {
            if (i == 0 || j == 0 || i == board.size() - 1
                    || j == board[0].size() - 1) {
                // the most outside row or column
                return false;
            } else {
                // temp to set tag and dfs four directions
                tag[i][j] = true;
                if (isWrapped(i - 1, j, board, tag)
                        && isWrapped(i + 1, j, board, tag)
                        && isWrapped(i, j - 1, board, tag)
                        && isWrapped(i, j + 1, board, tag)) {
                    tag[i][j] = false; // must reset to false
                    return true;
                } else {
                    // restore tag
                    tag[i][j] = false;
                    return false;
                }
            }
        }
    }

    void solve(vector<vector<char>> &board)
    {
        int row = board.size();
        if (row <= 2)
            return;
        int col = board[0].size();
        if (col <= 2)
            return;

        vector<vector<bool>> tag(row, vector<bool>(col, false));

        for (int i = 1; i < row - 1; i++)
            for (int j = 1; j < col - 1; j++) {
                if (board[i][j] == 'O' && isWrapped(i, j, board, tag))
                    board[i][j] = 'X';
            }
    }
};

class Solution2
{
    void solve(vector<vector<char>> &board)
    {
        int row = board.size();
        if (row <= 2)
            return;
        int col = board[0].size();
        if (col <= 2)
            return;

        queue<pair<int, int>> q;

        // insert the most out side O's coordinate to queue
        for (int j = 0; j < col; j++) { // first row and last row
            if (board[0][j] == 'O')
                q.push(make_pair(0, j));
            if (board[row - 1][j] == 'O')
                q.push(make_pair(row - 1, j));
        }
        for (int i = 0; i < row; i++) { // first column and last column
            if (board[i][0] == 'O')
                q.push(make_pair(i, 0));
            if (board[i][col - 1] == 'O')
                q.push(make_pair(i, col - 1));
        }

        // BFS search
        // change 'O' to N if it cannot be set to X
        // the remain 'O' will be set to X in later, and N will be reset back to O
        while (!q.empty()) {
            pair<int, int> cord = q.front();
            q.pop();
            int x = cord.first, y = cord.second;

            board[x][y] = 'N';
            if (x - 1 >= 0 && board[x - 1][y] == 'O') // up
                q.push(make_pair(x - 1, y));
            if (x + 1 < row && board[x + 1][y] == 'O') // down
                q.push(make_pair(x + 1, y));
            if (y - 1 >= 0 && board[x][y - 1] == 'O') // left
                q.push(make_pair(x, y - 1));
            if (y + 1 < col && board[x][y + 1] == 'O') // right
                q.push(make_pair(x, y + 1));
        }

        // reset 'N' back to 'O' and set other 'O' to 'X'
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                if (board[i][j] == 'N')
                    board[i][j] = 'O';
            }
    }
};

void print_board(vector<vector<char>> &board)
{
    for (auto &row : board) {
        for (auto col : row)
            cout << col << ends;
        cout << endl;
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    Solution sol;
    Solution sol2;

    vector<vector<char>> board = { { 'X', 'X', 'X', 'X' },
        { 'X', 'O', 'O', 'X' }, { 'X', 'X', 'O', 'X' },
        { 'X', 'O', 'X', 'X' }
    };

    vector<vector<char>> board2 = { { 'X', 'X', 'X' }, { 'X', 'O', 'X' }, { 'X',
            'X', 'X'
        }
    };

    print_board(board);
    sol2.solve(board);
    print_board(board);

    print_board(board2);
    sol2.solve(board2);
    print_board(board2);

    return 0;
}
