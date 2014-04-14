/*

 Minimum Depth of Binary Tree

 Given a binary tree, find its minimum depth.

 The minimum depth is the number of nodes along the shortest path
 from the root node down to the nearest leaf node.

 */

#include <iostream>
#include <algorithm>
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
    int minDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        else if (!root->left) // be careful about tree has only one child
            return minDepth(root->right) + 1;
        else if (!root->right)
            return minDepth(root->left) + 1;
        else {
            int leftDepth = minDepth(root->left);
            int rightDepth = minDepth(root->right);
            return min(leftDepth, rightDepth) + 1;
        }
    }
};

// unrecursively
class Solution2
{
public:
    int minDepth(TreeNode *root)
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

            if (!cur->left && !cur->right) return level;

            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    Solution2 sol2;

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    TreeNode *root2 = new TreeNode(1); //
    root2->left = new TreeNode(2);

    cout << sol.minDepth(root) << endl;
    cout << sol.minDepth(root2) << endl;

    cout << sol2.minDepth(root) << endl;
    cout << sol2.minDepth(root2) << endl;

    return 0;
}
