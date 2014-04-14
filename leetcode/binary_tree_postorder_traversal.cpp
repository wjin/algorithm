/*

 Binary Tree Postorder Traversal

 Given a binary tree, return the postorder traversal of its nodes' values.

 For example:
 Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
 return [3,2,1].

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
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ret;
        stack<TreeNode*> s;
        TreeNode *cur = root, *prev = nullptr;

        while (cur || !s.empty()) {
            if (cur) { // traverse to the left
                s.push(cur);
                cur = cur->left;
            } else {
                cur = s.top();
                // judge whether it is back from right child
                if (cur->right && cur->right != prev) { // back from left child
                    cur = cur->right;
                    s.push(cur);
                    cur = cur->left;
                } else { // back from right child
                    s.pop();
                    ret.push_back(cur->val);
                    prev = cur;
                    cur = nullptr;
                }
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

    vector<int> ret = sol.postorderTraversal(root);

    for (auto t : ret)
        cout << t << ends;
    cout << endl;

    return 0;
}
