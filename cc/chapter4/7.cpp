/*

4.7

Design an algorithm and write code to find the first common ancestor of two
nodes in a binary tree. Avoid storing additional nodes in a data structure. NOTE:
This is not necessarily a binary search tree.

*/

#include <iostream>

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
    TreeNode* do_lca(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root) return nullptr;

        if (root == p || root == q) {
            return root;
        }

        TreeNode* left = do_lca(root->left, p, q);
        if (left && left != p && left != q) { // ancestor
            return left;
        }

        TreeNode* right = do_lca(root->right, p, q);
        if (right && right != p && right != q) { // ancestor
            return right;
        }

        if (left && right) return root; // ancestor
        return left ? left : right;
    }

    bool exist(TreeNode *root, TreeNode *t)
    {
        if (!root) return false;

        if (root == t) return true;

        return exist(root->left, t) || exist(root->right, t);
    }

public:
    int lca(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root || !exist(root, p) || !exist(root, q)) return -1;

        TreeNode* ans = do_lca(root, p, q);

        return ans->val;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    TreeNode *fake = (TreeNode*)(0x1000);

    TreeNode *root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    cout << sol.lca(root, root->left, nullptr) << endl;

    cout << sol.lca(root, root->left, fake) << endl;
    cout << sol.lca(root, fake, root->right) << endl;

    cout << sol.lca(root, root->left->left, root->right->right) << endl;
    cout << sol.lca(root, root->left->left, root->left->right) << endl;

    cout << sol.lca(root, root->left, root->left->right) << endl;

    return 0;
}
