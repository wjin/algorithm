/*

 Balanced Binary Tree

 Given a binary tree, determine if it is height-balanced.

 For this problem, a height-balanced binary tree is defined as a binary tree
 in which the depth of the two subtrees of every node never differ by more than 1.

 */

#include <iostream>
#include <algorithm>

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

// nlogn
class Solution
{
public:
    int getHeight(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return max(getHeight(root->left), getHeight(root->right)) + 1;
    }

    bool isBalanced(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        int leftHeight = getHeight(root->left);
        int rightHeiht = getHeight(root->right);
        return abs(leftHeight - rightHeiht) <= 1 && isBalanced(root->left)
               && isBalanced(root->right);
    }
};

class Solution2
{
private:
    bool isBalanced(TreeNode *t, int &depth)
    {
        if (!t) {
            depth = 0;
            return true;
        }

        int leftDepth = 0, rightDepth = 0;
        if (isBalanced(t->left, leftDepth) && isBalanced(t->right, rightDepth)) {
            if (abs(leftDepth - rightDepth) <= 1) {
                depth = max(leftDepth, rightDepth) + 1;
                return true;
            }
        }
        return false;
    }

public:
    bool isBalanced(TreeNode *root)
    {
        int depth = 0;
        return isBalanced(root, depth);
    }
};

// cracking the coding interview
// time complexity: O(n)
// space complexity: O(H), H is the height of tree
class Solution3
{
public:
    bool isBalanced(TreeNode *root)
    {
        return checkHeight(root) != -1;
    }

private:
    int checkHeight(TreeNode *t)
    {
        if (!t) return 0;

        int leftHeight = checkHeight(t->left);
        if (leftHeight == -1) return -1; // early return

        int rightHeight = checkHeight(t->right);
        if (rightHeight == -1) return -1; // early return

        // compare
        if (abs(leftHeight - rightHeight) > 1) return -1;

        return max(leftHeight, rightHeight) + 1; // return height
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    Solution2 sol2;
    Solution3 sol3;

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->left->left = new TreeNode(3);

    cout << sol.isBalanced(root) << endl;
    cout << sol.isBalanced(root2) << endl;

    cout << sol2.isBalanced(root) << endl;
    cout << sol2.isBalanced(root2) << endl;

    cout << sol3.isBalanced(root) << endl;
    cout << sol3.isBalanced(root2) << endl;

    return 0;
}
