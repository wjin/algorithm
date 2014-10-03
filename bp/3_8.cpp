#include<iostream>

using namespace std;

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
private:
    int depth(TreeNode *t, int &ret)
    {
        if (!t) return 0;

        int lDepth = depth(t->left, ret);
        int rDepth = depth(t->right, ret);

        ret = max(ret, lDepth + rDepth);
        return max(lDepth, rDepth) + 1;
    }

public:
    int treeDistance(TreeNode *root)
    {
        int ret = 0;
        depth(root, ret);
        return ret;
    }
};

int main()
{
    Solution sol;

    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(3);
    root->right->right = new TreeNode(5);

    TreeNode *root2 = new TreeNode(1);
    root2->right = new TreeNode(2);
    root2->right->right = new TreeNode(3);
    root2->right->right->right = new TreeNode(4);

    TreeNode *root3 = new TreeNode(1);
    // root3->left = new TreeNode(2);
    root3->right = new TreeNode(3);
    root3->right->left = new TreeNode(4);
    root3->right->right = new TreeNode(5);
    // root3->right->right->right = new TreeNode(8);
    root3->right->left->left = new TreeNode(6);
    root3->right->left->left->left = new TreeNode(7);

    cout << sol.treeDistance(root) << endl;
    cout << sol.treeDistance(root2) << endl;
    cout << sol.treeDistance(root3) << endl;
}
