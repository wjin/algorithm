/*
  Convert Sorted List to Binary Search Tree

  Given a singly linked list where elements are sorted in ascending order,
  convert it to a height balanced BST.
*/

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    TreeNode *createTree(ListNode *&head, int start, int end)
    {
        if (start > end) {
            return nullptr;
        } else { // start <= end
            int mid = start + (end - start) / 2;

            // create left sub tree recursively
            TreeNode *left = createTree(head, start, mid - 1);

            // create root node
            // don't exchange it with creaing right sub tree
            // be careuful about parameter 'head' is pointer reference
            TreeNode *root = new TreeNode(head->val);
            head = head->next;

            // create right sub tree recursively
            TreeNode *right = createTree(head, mid + 1, end);

            root->left = left;
            root->right = right;
            return root;
        }
    }

    TreeNode *sortedListToBST(ListNode *head)
    {
        int len = 0;
        ListNode *t = head;
        while (t) {
            len++;
            t = t->next;
        }
        return createTree(head, 0, len - 1);
    }
};

void print_list(ListNode *head)
{
    while (head) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << endl;
}

void print_tree_preorder(TreeNode *root)
{
    if (root) {
        cout << root->val << ends;
        print_tree_preorder(root->left);
        print_tree_preorder(root->right);
    }
}

void print_tree_inorder(TreeNode *root)
{
    if (root) {
        print_tree_inorder(root->left);
        cout << root->val << ends;
        print_tree_inorder(root->right);
    }
}

int main(int cnt, char*argv[])
{
    Solution sol;

    ListNode *list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);
    list->next->next->next->next = new ListNode(5);

    print_list(list);
    TreeNode *t = sol.sortedListToBST(list);

    print_tree_preorder(t);
    cout << endl;

    print_tree_inorder(t);
    cout << endl;

    return 0;
}
