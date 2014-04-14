/*

 Unique Paths

 A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 The robot can only move either down or right at any point in time. The robot is trying to reach
 the bottom-right corner of the grid (marked 'Finish' in the diagram below).

 How many possible unique paths are there?

 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // dp[m][n]

        // be careful with initialization
        dp[1][1] = 1;

        // calculate dp[i][j] from dp[1][1] to dp[m][n]
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (i != 1 || j != 1)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m][n];
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    cout << sol.uniquePaths(1, 1) << endl;
    cout << sol.uniquePaths(1, 2) << endl;
    cout << sol.uniquePaths(2, 1) << endl;
    cout << sol.uniquePaths(2, 2) << endl;
    cout << sol.uniquePaths(3, 7) << endl;

    return 0;
}
