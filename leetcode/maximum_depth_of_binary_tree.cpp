/*

 Maximum Depth of Binary Tree

 Given a binary tree, find its maximum depth.

 The maximum depth is the number of nodes along the longest path
 from the root node down to the farthest leaf node.

 */

#include <iostream>
#include <queue>

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

// recursively
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr) return 0;
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        return max(leftDepth, rightDepth) + 1;
    }
};

// unrecursively
class Solution2
{
public:
    int maxDepth(TreeNode *root)
    {
        if (!root) return 0;

        queue<TreeNode *> q;
        TreeNode *cur = nullptr;
        int level = 0, levelSize = 0;
        q.push(root);

        while (!q.empty()) {
            if (levelSize == 0 ) {
                levelSize = q.size();
                level++;
            }

            cur = q.front();
            q.pop();
            levelSize--;

            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }

        return level;
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

    cout << sol.maxDepth(root) << endl;
    cout << sol2.maxDepth(root) << endl;

    return 0;
}
