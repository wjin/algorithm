/*

 Binary Tree Preorder Traversal

 Given a binary tree, return the preorder traversal of its nodes' values.

 For example:
 Given binary tree {1,#,2,3},

   1
    \
     2
    /
   3


 return [1,2,3].

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
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        stack<TreeNode*> s;
        TreeNode *cur = root;

        while (cur || !s.empty()) {
            if (cur) {
                ret.push_back(cur->val);
                s.push(cur);
                cur = cur->left;
            } else {
                cur = s.top();
                s.pop();
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

    vector<int> ret = sol.preorderTraversal(root);

    for (auto t : ret)
        cout << t << ends;
    cout << endl;

    return 0;
}
