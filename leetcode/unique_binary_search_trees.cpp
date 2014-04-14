/*

 Unique Binary Search Trees

 Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

 For example,
 Given n = 3, there are a total of 5 unique BST's.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // equal to the number of binary trees with n elements(similar tree)

    // considering total element n, we can let i(1...n) to be root
    // and calculate number of left sub tree (1...i-1) iLeftNum and right sub tree (i+1...n) iRightNum
    // iLeftNum * iRightNum is the number of trees such that element i is root
    // totalNumber = sum(iLeftNum * iRightNum), i from 1 to n
    int numTrees(int n)
    {
        if (n < 0) return -1;  // error
        if (n == 0 || n == 1) return 1; // empty tree or one node tree

        vector<int> dp(n + 1);
        dp[0] = 1;
        // dp[i] means number of tree node 1...i
        // dp[i] = dp[j] * dp[i-j-1], j from 0 to i - 1, j is the number of left sub tree node
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }

        return dp[n];
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    cout << sol.numTrees(0) << endl;
    cout << sol.numTrees(1) << endl;
    cout << sol.numTrees(2) << endl;
    cout << sol.numTrees(3) << endl;

    return 0;
}
