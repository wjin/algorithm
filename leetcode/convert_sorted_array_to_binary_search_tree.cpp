/*

 Convert Sorted Array to Binary Search Tree

 Given an array where elements are sorted in ascending order,
 convert it to a height balanced BST.

 */

#include <iostream>
#include <vector>

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
    TreeNode *createTree(vector<int> &num, int start, int end)
    {
        if (start > end) {
            return nullptr;
        } else { // start <= end
            int mid = start + (end - start) / 2;
            // let the middle element as root
            TreeNode *root = new TreeNode(num[mid]);
            // create left child tree recursively
            root->left = createTree(num, start, mid - 1);
            // create right child tree recursively
            root->right = createTree(num, mid + 1, end);
            return root;
        }
    }

    TreeNode *sortedArrayToBST(vector<int> &num)
    {
        int len = num.size();
        if (len == 0)
            return nullptr;
        return createTree(num, 0, len - 1);
    }
};

void print_tree_preorder(TreeNode *root)
{
    if (root) {
        cout << root->val << ends;
        print_tree_preorder(root->left);
        print_tree_preorder(root->right);
    }
}

void print_tree_inorder(TreeNode *root)
{
    if (root) {
        print_tree_inorder(root->left);
        cout << root->val << ends;
        print_tree_inorder(root->right);
    }
}

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> num = { 1, 2, 3, 4, 5, 6, 7, 8 };

    TreeNode *root = sol.sortedArrayToBST(num);
    print_tree_preorder(root);
    cout << endl;
    print_tree_inorder(root);

    return 0;
}
