/*

 Given two binary trees A and B, write a function to check if B
 is a sub structure of A (not sub tree).

 */

#include <iostream>
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
    bool isSubStructure(TreeNode *t1, TreeNode *t2)
    {
        if (!t2) return true;
        if (!t1) return false;
        if (t1->val != t2->val)
            return false;

        return isSubStructure(t1->left, t2->left) && isSubStructure(t1->right, t2->right);
    }

    // preorder to find all nodes such that t1->val == t2->val
    // and then judge whether it is substructure
    bool isSubTree(TreeNode *t1, TreeNode *t2)
    {
        if (!t2) return true;
        if (!t1) return false;

        if (t1->val == t2->val && isSubStructure(t1, t2)) return true;
        return isSubTree(t1->left, t2) || isSubTree(t1->right, t2);
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    TreeNode *t11 = new TreeNode(0);
    t11->left = new TreeNode(1);

    TreeNode *t12 = new TreeNode(0);
    t12->right = new TreeNode(1);


    TreeNode *t21 = new TreeNode(1);
    t21->left = new TreeNode(0);
    t21->right = new TreeNode(2);
    t21->right->left = new TreeNode(3);
    t21->right->right = new TreeNode(1);
    t21->right->right->left = new TreeNode(5);

    TreeNode *t22 = new TreeNode(2);
    t22->left = new TreeNode(3);
    t22->right = new TreeNode(1);

    cout << sol.isSubTree(t11, t12) << endl;
    cout << sol.isSubTree(t21, t22) << endl;

    return 0;
}
