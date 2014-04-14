/*

   Unique Binary Search Trees II

   Given n, generate all structurally unique BST's (binary search trees)
   that store values 1...n.

   For example,
   Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

   confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.

*/

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    vector<TreeNode *> generate(int start, int end)
    {
        vector<TreeNode *> subTree;
        if (start > end) { // empty tree
            subTree.push_back(nullptr);
            return subTree;
        }

        // let k be root, and construct left/right sub tree recursively
        for (int k = start; k <= end; k++) {
            vector<TreeNode *> leftSubTree = generate(start, k - 1); // construct left sub tree
            vector<TreeNode *> rightSubTree = generate(k + 1, end); // construct right sub tree

            // construct tree
            for (auto left : leftSubTree) {
                for (auto right : rightSubTree) {
                    TreeNode *root = new TreeNode(k); //  create root node
                    root->left = left;
                    root->right = right;
                    subTree.push_back(root);
                }
            }
        }

        return subTree;
    }

    vector<TreeNode *> generateTrees(int n)
    {
        if (n < 0) return vector<TreeNode *>();

        // bug: n == 0, empty tree, vector must have one nullptr element
        return generate(1, n);
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

    vector<TreeNode *> ret = sol.generateTrees(3);
    for (auto e : ret) {
        print_tree_preorder(e);
        cout << endl << "----------------" << endl;
        print_tree_inorder(e);
        cout << endl << "================" << endl;
    }

    return 0;
}
