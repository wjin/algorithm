/*

 Triangle

 Given a triangle, find the minimum path sum from top to bottom.
 Each step you may move to adjacent numbers on the row below.

 For example, given the following triangle

 [
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
 ]
 The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

 Note:
 Bonus point if you are able to do this using only O(n) extra space,
 where n is the total number of rows in the triangle.

 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // O(n) space complexity
    int minimumTotal(vector<vector<int> > &triangle)
    {
        // dp array size is the last level of triangle
        vector<int> dp(triangle[triangle.size() - 1].size(), 0);

        // traverse each level number from top to bottom
        for (int i = 0; i < triangle.size(); i++) {
            int level_len = triangle[i].size();

            // must calculate from back to front as we will use dp[j-1]
            for (int j = level_len - 1; j >= 0; j--) {
                if (j == 0) // first element
                    dp[j] = dp[j] + triangle[i][j];
                else if (j == level_len - 1) // last element
                    dp[j] = dp[j - 1] + triangle[i][j];
                else // middle element
                    dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j];
            }
        }

        int ret = INT_MAX;
        for (auto t : dp) {
            ret = min(t, ret);
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
    vector<vector<int> > v = { { 2 }, { 3, 4 }, { 6, 5, 7 }, { 4, 1, 8, 3 } };

    Solution sol;
    cout << sol.minimumTotal(v) << endl;

    return 0;
}
