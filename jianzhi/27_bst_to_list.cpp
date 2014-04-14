/*

   convert BST to double linked list

 */

#include <iostream>

using namespace std;

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;  // list next pointer
    TreeNode *right; // list prev pointer
    TreeNode(int x) :
        val(x), left(NULL), right(NULL)
    {
    }
};

typedef TreeNode ListNode;

// recursive
class Solution
{
private:
    // construct cycle list such that we can find list tail easily
    ListNode * convert(TreeNode *t)
    {
        if (!t) return nullptr;

        ListNode *leftHead = convert(t->left);
        ListNode *rightHead = convert(t->right);

        // merge t to list
        if (leftHead) {
            ListNode *leftTail = leftHead->right; // cycle list, right is the same to prev

            leftTail->left = t;
            t->right = leftTail;

            t->left = leftHead;
            leftHead->right = t;
        } else {
            t->left = t->right = t;
            leftHead = t;
        }

        // merge right list
        if (rightHead) {
            ListNode *leftTail = leftHead->right;
            ListNode *rightTail = rightHead->right;

            leftTail->left = rightHead;
            rightHead->right = leftTail;

            rightTail->left = leftHead;
            leftHead->right = rightTail;
        }

        return leftHead;
    }

public:
    ListNode * bstToList(TreeNode *root)
    {
        ListNode *head = nullptr;
        if (!root) return head;
        head = convert(root);

        // split cycle list
        head->right->left = nullptr;
        head->right = nullptr;

        return head;
    }
};

void print_list(ListNode *root)
{
    ListNode *p = root;
    while (p) {
        cout << p->val << ' ';
        p = p->left;
    }
    cout << endl;

    p = root;
    while (p->left) p = p->left;
    while (p) {
        cout << p->val << ' ';
        p = p->right;
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    Solution sol;

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(6);

    TreeNode *root2 = new TreeNode(3);
    root2->left = new TreeNode(2);
    root2->left->left = new TreeNode(1);

    TreeNode *root3 = new TreeNode(3);
    root3->right = new TreeNode(5);
    root3->right->left = new TreeNode(4);
    root3->right->right = new TreeNode(6);

    ListNode *ret = sol.bstToList(root);
    print_list(ret);

    ret = sol.bstToList(root2);
    print_list(ret);

    ret = sol.bstToList(root3);
    print_list(ret);

    return 0;
}
