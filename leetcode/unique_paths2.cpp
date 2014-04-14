/*
 Unique Paths II

 Follow up for "Unique Paths":

 Now consider if some obstacles are added to the grids. How many unique paths would there be?

 An obstacle and empty space is marked as 1 and 0 respectively in the grid.

 For example,
 There is one obstacle in the middle of a 3x3 grid as illustrated below.

 [
 [0,0,0],
 [0,1,0],
 [0,0,0]
 ]

 The total number of unique paths is 2.
 Note: m and n will be at most 100.

 */

#include <iostream>
#include <vector>


using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid)
    {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // dp[m][n]

        dp[0][1] = 1; // be careful with initialization

        // calculate dp[i][j] from dp[1][1] to dp[m][n]
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++) {
                if (obstacleGrid[i - 1][j - 1] == 1)  // i-1, j-1
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }

        return dp[m][n];
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<vector<int> > v = { { 0, 0, 0 }, { 0, 1, 0 }, { 0, 0, 0 } };

    cout << sol.uniquePathsWithObstacles(v) << endl;

    return 0;
}
