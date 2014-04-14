/*

  Get mirror tree of a given Binary Tree

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

// recursive solution
class Solution
{
public:
    TreeNode * getMirror(TreeNode *root)
    {
        if (!root) return root;

        TreeNode *left = getMirror(root->right);
        TreeNode *right = getMirror(root->left);

        root->left = left;
        root->right = right;

        return root;
    }
};

void print_tree_preorder(TreeNode *root)
{
    if (root) {
        cout << root->val << ' ';
        print_tree_preorder(root->left);
        print_tree_preorder(root->right);
    }
}

void print_tree_inorder(TreeNode *root)
{
    if (root) {
        print_tree_inorder(root->left);
        cout << root->val << ' ';
        print_tree_inorder(root->right);
    }
}

int main(int argc, char *argv[])
{
    Solution sol;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    TreeNode *mirror = sol.getMirror(root);
    print_tree_preorder(mirror);
    cout << endl;
    print_tree_inorder(mirror);
    cout << endl;

    return 0;
}
