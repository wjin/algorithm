/*

 Binary Tree Level Order Traversal

 Given a binary tree, return the level order traversal of its nodes' values.
 (ie, from left to right, level by level).

 For example:
 Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7

 return its level order traversal as:
 [
 [3],
 [9,20],
 [15,7]
 ]

 */

#include <iostream>
#include <vector>
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

class Solution
{
public:
    vector<vector<int> > levelOrder(TreeNode *root)
    {
        queue<TreeNode*> q;
        TreeNode *cur = root;
        vector<vector<int>> ret;
        int levelSize = 0;

        if (cur) q.push(cur);

        while (!q.empty()) {
            // judge whether start a new level
            if (levelSize == 0) {
                levelSize = q.size();
                ret.push_back(vector<int>()); //
            }

            cur = q.front();
            q.pop();

            // add element for this level
            ret.back().push_back(cur->val);
            levelSize--;

            if (cur->left != nullptr)
                q.push(cur->left);
            if (cur->right != nullptr)
                q.push(cur->right);
        }

        return ret;
    }
};

// recursively
class Solution2
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ret;
        levelOrder(root, ret, 0);
        return ret;
    }

private:
    void levelOrder(TreeNode *t, vector<vector<int>> &ret, size_t level)
    {
        if (!t) return;

        if (level >= ret.size()) ret.push_back(vector<int>());

        ret[level].push_back(t->val);
        levelOrder(t->left, ret, level + 1);
        levelOrder(t->right, ret, level + 1);
    }
};

void print_ret(vector<vector<int>> &ret)
{
    for (auto &row : ret) {
        for (auto col : row)
            cout << col << ' ';
        cout << endl;
    }
}

int main(int argc, char *argv[])
{
    Solution sol;
    Solution2 sol2;

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    vector<vector<int>> ret = sol.levelOrder(root);
    print_ret(ret);

    ret = sol2.levelOrder(root);
    print_ret(ret);

    return 0;
}
