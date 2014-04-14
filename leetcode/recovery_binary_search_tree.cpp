/*

 Recover Binary Search Tree

 Two elements of a binary search tree (BST) are swapped by mistake.
 Recover the tree without changing its structure.

 Note:
 A solution using O(n) space is pretty straight forward.
 Could you devise a constant space solution?

 */

#include <iostream>
#include <vector>
#include <stack>

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

// O(n) due to stack
class Solution
{
public:
    void recoverTree(TreeNode *root)
    {
        stack<TreeNode*> s;
        TreeNode *cur = root;
        TreeNode *prevCur = nullptr; // previous tree node in inorder traversal
        TreeNode *mis1 = nullptr; // first out of order tree node
        TreeNode *prevMis1 = nullptr; // previous mis1 in inorder traversal
        TreeNode *mis2 = nullptr; // second out of order tree node
        TreeNode *prevMis2 = nullptr; // previous mis2 in inorder traversal, useless...

        while (cur || !s.empty()) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            } else {
                cur = s.top();
                s.pop();

                // judge
                if (prevCur == nullptr)
                    prevCur = cur; // first node in inorder traverse
                else {
                    if (prevCur->val > cur->val) {
                        if (mis1 == nullptr) {
                            prevMis1 = prevCur;
                            mis1 = cur;
                        } else {
                            prevMis2 = prevCur;
                            mis2 = cur;
                            break;
                        }
                    }
                    prevCur = cur; // update prevCur
                }

                cur = cur->right;
            }
        }

        if (mis2 == nullptr) { // case t1, t2
            swap(prevMis1->val, mis1->val);
        } else {
            // case t3
            // mis1 == prevMis2
            // three nodes:  a b c:  a > b; b > c
            // swap(a, c) can make them in order

            // case t4
            // initial condition: a b c d : a > b; c > d

            // swap c with a or b
            // c b a d : invalid
            // a c b d : invalid

            // swap d with a or b
            // d b c a
            // a d c b : invalid

            // only swap(a, d) can make them in order

            swap(prevMis1->val, mis2->val);
        }
    }
};

// Morris traversal solution
// O(1) space complexity
class Solution2
{
private:
    void judge(pair<TreeNode *, TreeNode *> &broken, TreeNode *prev, TreeNode *cur)
    {
        if (prev && prev->val > cur->val) { // broken
            if (!broken.first) {
                // first broken node must be prev because we swapped a bigger node to be here
                // we could be aware of this broken until traversing its next node(cur)
                broken.first = prev;
            }

            // obviously, second broken node must be cur as it is smaller
            // always set broken.second as tree may have only two nodes
            // that means we found two broken nodes at the same time
            broken.second = cur;
        }
    }

public:
    void recoverTree(TreeNode *root)
    {
        TreeNode *cur = root;
        TreeNode *prev = nullptr;
        TreeNode *t = nullptr;

        pair<TreeNode *, TreeNode *> broken;

        while (cur) {
            if (!cur->left) {
                judge(broken, prev, cur);
                prev = cur;
                cur = cur->right;
            } else {
                t = cur->left; // left child
                while (t->right && t->right != cur) t = t->right; // rightmost

                if (!t->right) { // thread it
                    t->right = cur;
                    cur = cur->left;
                } else { // delete thread
                    t->right = nullptr;

                    judge(broken, prev, cur);
                    prev = cur;
                    cur = cur->right;
                }
            }
        }

        swap(broken.first->val, broken.second->val);
    }
};

void print_tree(TreeNode *root)
{
    if (root) {
        print_tree(root->left);
        cout << root->val << ends;
        print_tree(root->right);
    }
}

int main(int argc, char *argv[])
{
    Solution2 sol;

    TreeNode *t1 = new TreeNode(0);
    t1->left = new TreeNode(1);

    TreeNode *t2 = new TreeNode(1);
    t2->right = new TreeNode(0);

    TreeNode *t3 = new TreeNode(2);
    t3->left = new TreeNode(3);
    t3->right = new TreeNode(1);

    TreeNode *t4 = new TreeNode(2);
    t4->left = new TreeNode(4);
    t4->right = new TreeNode(5);
    t4->right->left = new TreeNode(3);
    t4->right->left->right = new TreeNode(1);

    print_tree(t1);
    sol.recoverTree(t1);
    print_tree(t1);
    cout << endl;

    print_tree(t2);
    sol.recoverTree(t2);
    print_tree(t2);
    cout << endl;

    print_tree(t3);
    sol.recoverTree(t3);
    print_tree(t3);
    cout << endl;

    print_tree(t4);
    sol.recoverTree(t4);
    print_tree(t4);

    return 0;
}
