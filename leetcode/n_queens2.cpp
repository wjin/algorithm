/*

 N-Queens ||

 The n-queens puzzle is the problem of placing n queens on an n x n chessboard
 such that no two queens attack each other.

 Now, instead outputting board configurations, return the total number of distinct solutions.

 */

#include <iostream>
#include <vector>
#include <string>
#include <cstdlib> // abs
#include <cstring>

using namespace std;

// the original implementation in Question-51 is a little slow.
// using it cannot pass large data test of q-52.

class Solution
{
private:
    int ret;
    int row[100];     // row[i] store the Queen's place of row i
    bool canUse[100];  // tag whether column i is used

public:
    // just verify diagonal
    bool check(int x, int y)   // row[x] = y
    {
        for (int i = 1; i <= x; i++) {
            if (abs(row[i] - y) == abs(i - x)) // attack
                return false;
        }

        return true; // no attack
    }

    //  backtrack
    void dfs(int current, int n)
    {
        if (current > n) {
            ret++;
            return;
        }

        // current <= n
        for (int col = 1; col <= n; col++) {
            if (canUse[col] && check(current, col)) {
                canUse[col] = false;
                row[current] = col;
                dfs(current + 1, n);
                row[current] = 0;
                canUse[col] = true;
            }
        }
    }

    int totalNQueens(int n)
    {
        ret = 0;
        memset(canUse, true, sizeof(canUse));

        dfs(1, n);

        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    cout << sol.totalNQueens(13) << endl;

    return 0;
}
