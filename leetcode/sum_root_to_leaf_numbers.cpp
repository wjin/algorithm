/*

 Sum Root to Leaf Numbers

 Given a binary tree containing digits from 0-9 only,
 each root-to-leaf path could represent a number.

 An example is the root-to-leaf path 1->2->3 which represents the number 123.

 Find the total sum of all root-to-leaf numbers.

 For example,

  1
 / \
2   3

 The root-to-leaf path 1->2 represents the number 12.
 The root-to-leaf path 1->3 represents the number 13.

 Return the sum = 12 + 13 = 25.

 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for binary tree
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) :
        val(x), left(NULL), right(NULL)
    {
    }
};

// post unrecursive traverse
class Solution
{
public:
    int sumNumbers(TreeNode *root)
    {
        if (!root) return 0;

        vector<TreeNode*> v;
        TreeNode *cur = root;
        TreeNode *prev = nullptr;
        int sum = 0, tsum = 0;

        // post order un-recursive traverse tree
        while (cur || !v.empty()) {
            if (cur) {
                v.push_back(cur);
                tsum = tsum * 10 + cur->val;
                cur = cur->left;
            } else {
                cur = v.back();

                if (cur->right && cur->right != prev) {
                    cur = cur->right;
                    v.push_back(cur);
                    tsum = tsum * 10 + cur->val;
                    cur = cur->left;
                } else {
                    v.pop_back();
                    if (!cur->left && !cur->right) {
                        sum += tsum; // leaf, accumulate tsum to sum
                    }
                    tsum /= 10;

                    prev = cur;
                    cur = nullptr;
                }
            }
        }

        return sum;
    }
};

// preorder recursive traverse
class Solution2
{
    void getSum(TreeNode *t, int cur, int &sum)
    {
        if (t) {
            if (!t->left && !t->right) {
                sum += cur * 10 + t->val;
                return;
            }
            getSum(t->left, cur * 10 + t->val, sum);
            getSum(t->right, cur * 10 + t->val, sum);
        }
    }

public:
    int sumNumbers(TreeNode *root)
    {
        int sum = 0, cur = 0;
        getSum(root, cur, sum);
        return sum;
    }
};

int main(int argc, char* argv[])
{
    Solution sol;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    cout << sol.sumNumbers(root) << endl;

    return 0;
}
