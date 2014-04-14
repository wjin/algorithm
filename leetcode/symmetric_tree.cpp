/*

Symmetric Tree

Given a binary tree, check whether it is a mirror of itself
(ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following is not:
    1
   / \
  2   2
   \   \
   3    3

Note:
Bonus points if you could solve it both recursively and iteratively.

*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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

// recursive solution
class Solution
{
public:
    bool symmetric(TreeNode *t1, TreeNode *t2)
    {
        if (t1 == nullptr && t2 == nullptr)
            return true;
        if (!t1 || !t2)
            return false;
        if (t1->val != t2->val)
            return false;
        return symmetric(t1->left, t2->right) && symmetric(t1->right, t2->left);
    }

    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        return symmetric(root->left, root->right);
    }
};

// iterative solution
class Solution2
{
public:
    // whether level node is a palindrome
    bool isValid(vector<int> &v)
    {
        int start = 0, end = v.size() - 1;
        while (start < end) {
            if (v[start] != v[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    bool judgeByLevelOrder(TreeNode *root)
    {
        queue<TreeNode*> q;
        TreeNode *cur = root;
        vector<int> curLevelNode;

        int levelSize = 0;
        q.push(cur);
        curLevelNode.push_back(cur->val);

        while (!q.empty()) {
            // judge whether start a new level
            if (levelSize == 0) {
                levelSize = q.size();
                if (!isValid(curLevelNode))
                    return false;
                curLevelNode.clear();
            }

            cur = q.front();
            q.pop();

            // add element for this level
            // INT_MIN is a magic
            // wish tree nodes do not include it
            curLevelNode.push_back(cur ? cur->val : INT_MIN);
            levelSize--;

            if (cur) {
                q.push(cur->left); // push nullptr also
                q.push(cur->right); // push nullptr also
            }
        }
        return true;
    }

    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        return judgeByLevelOrder(root);
    }
};

// another simple iterative solution
class Solution3
{
public:
    bool isSymmetric(TreeNode *root)
    {
        if (!root) return true;

        queue<TreeNode *> q;
        TreeNode *t1, *t2;

        q.push(root->left);
        q.push(root->right);

        while (!q.empty()) {
            t1 = q.front();
            q.pop();
            t2 = q.front();
            q.pop();

            if (!t1 && !t2) continue; // match, both are null tree
            if (!t1 || !t2) return false; // not match
            if (t1->val != t2->val) return false; // not match

            // push null sub tree to queue so that
            // we could perfectly match
            // left matches right subtree
            q.push(t1->left);
            q.push(t2->right);

            q.push(t1->right);
            q.push(t2->left);
        }

        return true;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    Solution2 sol2;
    Solution3 sol3;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);

    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(2);
    root2->left->left = new TreeNode(3);

    cout << sol.isSymmetric(root) << endl;
    cout << sol.isSymmetric(root2) << endl;

    cout << sol2.isSymmetric(root) << endl;
    cout << sol2.isSymmetric(root2) << endl;

    cout << sol3.isSymmetric(root) << endl;
    cout << sol3.isSymmetric(root2) << endl;

    return 0;
}
