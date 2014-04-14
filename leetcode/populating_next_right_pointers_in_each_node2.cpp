/*

 Populating Next Right Pointers in Each Node ||


 Follow up for problem "Populating Next Right Pointers in Each Node".

 What if the given tree could be any binary tree? Would your previous solution still work?

 Note:

 You may only use constant extra space.
 For example,
 Given the following binary tree,
         1
       /  \
      2    3
     / \    \
    4   5    7

 After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL

 */

#include <iostream>
#include <queue>

using namespace std;

//Definition for binary tree
struct TreeLinkNode {
    int val;
    TreeLinkNode *left;
    TreeLinkNode *right;
    TreeLinkNode *next;
    TreeLinkNode(int x) :
        val(x), left(NULL), right(NULL), next(NULL)
    {
    }
};

// O(n) space complexity
class Solution
{
public:
    void levelOrderTraversal(TreeLinkNode *root)
    {
        queue<TreeLinkNode*> q;
        TreeLinkNode *cur = root;

        q.push(cur);
        int levelSize = 0;

        while (!q.empty()) {
            // judge whether start a new level
            if (levelSize == 0) {
                levelSize = q.size();
            }

            cur = q.front();
            q.pop();
            levelSize--;
            if (levelSize != 0)
                cur->next = q.front();

            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
    }

    void connect(TreeLinkNode *root)
    {
        if (!root)
            return;
        levelOrderTraversal(root);
    }
};

// O(1) space complexity
class Solution2
{
public:
    void connect(TreeLinkNode *root)
    {
        TreeLinkNode *cur = root;
        TreeLinkNode *nextLevel = nullptr; // next level head
        TreeLinkNode *prev = nullptr; // previous node in current level

        while (cur) {
            // reset temp variable
            nextLevel = nullptr;
            prev = nullptr;

            while (cur) {
                // store next level head
                if (!nextLevel) nextLevel = cur->left ? cur->left : cur->right;

                // link node according to prev pointer
                if (cur->left) {
                    if (prev) prev->next = cur->left;
                    prev = cur->left;
                }
                if (cur->right) {
                    if (prev) prev->next = cur->right;
                    prev = cur->right;
                }

                // next node in the same level
                // we just linked it by prev pointer
                cur = cur->next;
            }

            // traverse next level
            cur = nextLevel;
        }
    }
};

void print_tree_next_value(TreeLinkNode *root)
{
    if (root) {
        if (root->next) {
            cout << root->val << ends << root->next->val << endl;
        }
        print_tree_next_value(root->left);
        print_tree_next_value(root->right);
    }
}

int main(int argc, char *argv[])
{
    Solution sol;

    TreeLinkNode *root = new TreeLinkNode(1);
    root->left = new TreeLinkNode(2);
    root->right = new TreeLinkNode(3);
    root->left->left = new TreeLinkNode(4);
    root->left->right = new TreeLinkNode(5);
    // root->right->left = new TreeLinkNode(6);
    root->right->right = new TreeLinkNode(7);

    print_tree_next_value(root);
    sol.connect(root);
    print_tree_next_value(root);

    return 0;
}
