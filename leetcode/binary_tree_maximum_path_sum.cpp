/*

 Binary Tree Maximum Path Sum
 Given a binary tree, find the maximum path sum.

 The path may start and end at any node in the tree.

 For example:
 Given the below binary tree,

       1
      / \
     2   3

 Return 6.

 */

#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

//Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL)
    {
    }
};

class Solution
{
public:
    int getPathSum(TreeNode *root, int &curSum)
    {
        if (!root) return 0;

        int lMax = getPathSum(root->left, curSum);
        int rMax = getPathSum(root->right, curSum);

        // sum cross this node
        int tSum = root->val;
        if (lMax > 0) // >
            tSum += lMax;
        if (rMax > 0)
            tSum += rMax;

        curSum = max(curSum, tSum);

        // return max path sum ending with root
        // so that we can combine it with other paths
        // only one direction (left or right) is returned
        return max({root->val, lMax + root->val, rMax + root->val}); // be careful
    }

    int maxPathSum(TreeNode *root)
    {
        int maxSum = INT_MIN;
        getPathSum(root, maxSum);
        return maxSum;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(-2);

    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(-2);
    root2->right = new TreeNode(2);
    root2->left->left = new TreeNode(3);

    TreeNode *root3 = new TreeNode(-1);

    TreeNode *root4 = new TreeNode(-1);
    root4->left = new TreeNode(1);
    root4->right = new TreeNode(-2);

    cout << sol.maxPathSum(root) << endl;
    cout << sol.maxPathSum(root2) << endl;
    cout << sol.maxPathSum(root3) << endl;
    cout << sol.maxPathSum(root4) << endl;

    return 0;
}
