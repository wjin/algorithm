/*

 Binary Tree Inorder Traversal

 Given a binary tree, return the inorder traversal of its nodes' values.

 For example:
 Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3


 return [1,3,2].

 Note: Recursive solution is trivial, could you do it iteratively?

 */

#include <iostream>
#include <vector>
#include <stack>

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
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        stack<TreeNode*> s;
        TreeNode *cur = root;

        while (cur || !s.empty()) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            } else {
                cur = s.top();
                s.pop();
                ret.push_back(cur->val);
                cur = cur->right;
            }
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    TreeNode *root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> ret = sol.inorderTraversal(root);

    for (auto t : ret)
        cout << t << ends;
    cout << endl;

    return 0;
}
