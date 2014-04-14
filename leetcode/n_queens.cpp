/*

 N-Queens

 The n-queens puzzle is the problem of placing n queens on an n x n chessboard
 such that no two queens attack each other.

 Given an integer n, return all distinct solutions to the n-queens puzzle.
 Each solution contains a distinct board configuration of the n-queens' placement,
 where 'Q' and '.' both indicate a queen and an empty space respectively.

 For example,
 There exist two distinct solutions to the 4-queens puzzle:

 [
 [".Q..",  // Solution 1
 "...Q",
 "Q...",
 "..Q."],

 ["..Q.",  // Solution 2
 "Q...",
 "...Q",
 ".Q.."]
 ]

 */

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // abs

using namespace std;

class Solution
{
private:
    vector<vector<string>> ret;
public:
    void generate_result(vector<int> &row)
    {
        vector<string> t;
        for (int i = 1; i < row.size(); i++) {
            string tmp;
            for (int j = 1; j < row.size(); j++)
                if (j == row[i])
                    tmp += 'Q';
                else
                    tmp += '.';
            t.push_back(tmp);
        }

        ret.push_back(t);
    }

    bool judge(vector<int> &row)
    {
        for (int i = 1; i < row.size(); i++) {
            if (row[i] == 0) // no queen, continue
                continue;
            for (int j = i + 1; j < row.size(); j++) {
                if (row[j] == 0) // no queen, continue
                    continue;
                if (row[i] == row[j] || abs(row[i] - row[j]) == abs(i - j)) // attack
                    return false;
            }
        }

        return true; // no attack
    }

    //  backtrack
    void dfs(vector<int> &row, int start, int end)
    {
        if (start > end) {
            generate_result(row);
            return;
        } else { // start <= end
            for (int i = 1; i <= end; i++) {
                row[start] = i;
                if (judge(row))
                    dfs(row, start + 1, end);
                row[start] = 0; // reset queen place
            }
        }
    }

    vector<vector<string> > solveNQueens(int n)
    {
        vector<int> row(n + 1); // row[i] store the Queen's place of row i

        ret.clear();
        dfs(row, 1, n);
        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    vector<vector<string>> ret = sol.solveNQueens(8);

    for (auto &v : ret) {
        for (auto s : v)
            cout << s << endl;
        cout << endl;
    }

    return 0;
}
