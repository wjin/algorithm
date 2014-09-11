/*

 Path Sum II

 Given a binary tree and a sum, find all root-to-leaf paths
 where each path's sum equals the given sum.

 For example:
 Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \    / \
        7    2  5   1

 return
 [
  [5,4,11,2],
  [5,8,4,5]
 ]

 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL)
    {
    }
};

// post order unrecursively
class Solution
{
public:
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<vector<int>> ret;
        vector<int> path;
        vector<TreeNode*> v;
        TreeNode *cur = root, *prev = nullptr;
        int tsum = 0;

        // postorder traverse tree
        while (cur || !v.empty()) {
            if (cur) {
                v.push_back(cur);
                path.push_back(cur->val);
                tsum += cur->val;

                cur = cur->left;
            } else {
                cur = v.back();

                if (cur->right && cur->right != prev) {
                    cur = cur->right;

                    v.push_back(cur);
                    path.push_back(cur->val);
                    tsum += cur->val;

                    cur = cur->left;
                } else {
                    v.pop_back();
                    if (tsum == sum && !cur->left && !cur->right) {
                        ret.push_back(path);
                    }
                    path.pop_back();
                    tsum -= cur->val;

                    prev = cur;
                    cur = nullptr;
                }
            }
        }

        return ret;
    }
};

// pre order revursively
class Solution2
{
private:
    void dfs(TreeNode *t, vector<vector<int>> &ret, vector<int> &curPath, int curSum)
    {
        if (t) {
            curPath.push_back(t->val); // record parent path

            if (!t->left && !t->right && curSum == t->val) ret.push_back(curPath);

            dfs(t->left, ret, curPath, curSum - t->val);
            dfs(t->right, ret, curPath, curSum - t->val);

            curPath.pop_back(); // pop path
        }
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int sum)
    {
        vector<vector<int>> ret;
        if (!root) return ret;

        vector<int> curPath;
        dfs(root, ret, curPath, sum);
        return ret;
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

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(5);

    vector<vector<int>> ret = sol.pathSum(root, 7);
    print_ret(ret);

    ret = sol2.pathSum(root, 7);
    print_ret(ret);

    return 0;
}
