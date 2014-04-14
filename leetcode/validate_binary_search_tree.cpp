/*

 Validate Binary Search Tree

 Given a binary tree, determine if it is a valid binary search tree (BST).

 Assume a BST is defined as follows:

 The left subtree of a node contains only nodes with keys less than the node's key.
 The right subtree of a node contains only nodes with keys greater than the node's key.
 Both the left and right subtrees must also be binary search trees.

 */

#include <iostream>
#include <vector>
#include <stack>
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
    bool isValidBST(TreeNode *root)
    {
        stack<TreeNode*> s;
        TreeNode *cur = root;
        TreeNode *prev = nullptr; // previous node of inorder traverse

        while (cur || !s.empty()) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            } else {
                cur = s.top();
                s.pop();

                // judge
                if (prev == nullptr)
                    prev = cur; // first node in inorder traverse
                else {
                    if (prev->val >= cur->val) // =
                        return false;
                    prev = cur;
                }
                cur = cur->right;
            }
        }
        return true;
    }
};

class Solution2
{
public:
    bool isValidBST(TreeNode *root)
    {
        return isValidBST(root, INT_MIN, INT_MAX);
    }

private:
    bool isValidBST(TreeNode *t, int lower, int upper)
    {
        if (!t) return true;
        if (t->val <= lower || t->val >= upper) return false;
        return isValidBST(t->left, lower, t->val) &&
               isValidBST(t->right, t->val, upper);
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    Solution2 sol2;

    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(2);

    bool ret = sol.isValidBST(root);
    cout << ret << endl;

    ret = sol2.isValidBST(root);
    cout << ret << endl;

    return 0;
}
