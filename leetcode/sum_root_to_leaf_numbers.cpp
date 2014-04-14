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
private:
    int sum;
public:
    void calSum(vector<TreeNode*> &v)
    {
        int t = 0;
        for (auto e : v)
            t = t * 10 + e->val;
        sum += t;
    }

    int getSum(TreeNode *t)
    {
        vector<TreeNode*> v;
        TreeNode *p = t;
        TreeNode *prev = nullptr;
        sum = 0;

        // post order un-recursive traverse tree
        // when encounter a leaf, path was stored in vector array
        while (p || !v.empty()) {
            if (p) {
                v.push_back(p);
                p = p->left;
            } else {
                p = v.back();
                if (p->right && p->right != prev) {
                    p = p->right;
                    v.push_back(p);
                    p = p->left;
                } else {
                    if (!p->left && !p->right)
                        calSum(v); // leaf, accumulate path to sum
                    v.pop_back();
                    prev = p;
                    p = nullptr;
                }
            }
        }

        return sum;
    }

    int sumNumbers(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return getSum(root);
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
