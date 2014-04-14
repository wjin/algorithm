
/*

 Minimum Path Sum

 Given a m x n grid filled with non-negative numbers, find a path
 from top left to bottom right which minimizes the sum of all numbers along its path.

 Note: You can only move either down or right at any point in time.

 */

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int> > &grid)
    {
        int row = grid.size();
        if (row == 0)
            return 0;
        int col = grid[0].size();
        if (col == 0)
            return 0;

        vector<vector<int>> dp(row, vector<int>(col, 0));

        dp[0][0] = grid[0][0];
        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++) {
                if (i == 0 && j == 0)
                    continue;
                else if (i == 0)
                    dp[i][j] = dp[i][j - 1] + grid[i][j];
                else if (j == 0)
                    dp[i][j] = dp[i - 1][j] + grid[i][j];
                else {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
                }
            }

        return dp[row - 1][col - 1];
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<vector<int>> grid = { { 1, 1, 3 }, { 2, 0, 0 }, { 3, 1, 1 } };

    cout << sol.minPathSum(grid) << endl;

    return 0;
}
