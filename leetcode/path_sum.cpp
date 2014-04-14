/*

 Path Sum

 Given a binary tree and a sum, determine if the tree has a root-to-leaf path
 such that adding up all the values along the path equals the given sum.

 For example:
 Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1

 return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

 */

#include <iostream>
#include <vector>

using namespace std;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL)
    {
    }
};

// unrecursively
class Solution
{
public:
    int getPathSum(vector<TreeNode *> &v)
    {
        int sum = 0;
        for (auto e : v)
            sum += e->val;
        return sum;
    }

    bool hasPathSum(TreeNode *root, int sum)
    {
        vector<TreeNode*> v;
        TreeNode *cur = root, *prev = nullptr;

        // postorder traverse tree
        while (cur || !v.empty()) {
            if (cur) {
                v.push_back(cur);
                cur = cur->left;
            } else {
                cur = v.back();

                if (cur->right && cur->right != prev) {
                    cur = cur->right;
                    v.push_back(cur);
                    cur = cur->left;
                } else {
                    // judge before pop_back
                    if (!cur->left && !cur->right && getPathSum(v) == sum)
                        return true;

                    v.pop_back();
                    prev = cur;
                    cur = nullptr;
                }
            }
        }

        return false;
    }
};

class Solution2
{
public:
    bool hasPathSum(TreeNode *root, int sum)
    {
        if (!root) return false;

        if (sum - root->val == 0 && !root->left && !root->right) {
            return true;
        }

        return hasPathSum(root->left, sum - root->val) ||
               hasPathSum(root->right, sum - root->val);
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    Solution2 sol2;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    cout << sol.hasPathSum(root, 7) << endl;
    cout << sol.hasPathSum(root, 4) << endl;

    cout << sol2.hasPathSum(root, 7) << endl;
    cout << sol2.hasPathSum(root, 4) << endl;

    return 0;
}
