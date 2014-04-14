#include <iostream>

using namespace std;

template <typename T>
class BinarySearchTree
{
private:
    struct TreeNode {
        T val;
        TreeNode *left, *right;
        TreeNode(const T x = 0) : val(x), left(nullptr), right(nullptr) {}
    };

    TreeNode *root;

    void preorder(TreeNode *t)
    {
        if (t) {
            cout << t->val << ' ';
            preorder(t->left);
            preorder(t->right);
        }
    }

    void inorder(TreeNode *t)
    {
        if (t) {
            inorder(t->left);
            cout << t->val << ' ';
            inorder(t->right);
        }
    }

    // core function to remove node
    bool remove(TreeNode *&t) // pointer reference
    {
        TreeNode *rm = t; // store the node to be removed

        if (t->right == nullptr) { // re-connect left child
            t = t->left;
        } else if (t->left == nullptr) { // re-connect right child
            t = t->right;
        } else { // both left and right are not nullptr
            // use left child's right most node to replace t
            // we do not remove t directly, just use data replace
            TreeNode *lc = t->left; // t's left child
            TreeNode *plc = t; // parent of lc

            // find right most child
            while (lc->right) {
                plc = lc;
                lc = lc->right;
            }

            rm = lc; // delete right most
            t->val = lc->val;
            if (plc == t) { // lc has no right child
                plc->left = lc->left;
            } else {
                plc->right = lc->left;
            }
        }

        delete rm;
        rm = nullptr;
        return true;
    }

    bool remove(TreeNode *&t, const T &val) // must be pointer reference
    {
        if (t == nullptr) return false;
        else if (t->val < val) return remove(t->right, val);
        else if (t->val > val) return remove(t->left, val);
        else {// find node, delete it
            return remove(t);
        }
    }

public:
    BinarySearchTree() : root(nullptr) {}

    // allow duplicate element
    // left->val <= root->val
    bool insert(const T &val)
    {
        TreeNode *t = new TreeNode(val);
        if (t == nullptr) {
            return false;
        }

        if (root == nullptr) {
            root = t;
            return true;
        }

        TreeNode *parent = nullptr, *cur = root;
        while (cur) {
            parent = cur;
            if (cur->val < val) cur = cur->right;
            else cur = cur->left;
        }

        if (parent->val < val) parent->right = t;
        else parent->left = t;

        return true;
    }

    bool remove(const T &val)
    {
        return remove(root, val);
    }

    bool search(const T &val)
    {
        TreeNode *cur = root;
        while (cur) {
            if (cur->val == val) return true;
            else if (cur->val < val) cur = cur->right;
            else cur = cur->left;
        }
        return false;
    }

    void dump()
    {
        preorder(root);
        cout << endl;
        inorder(root);
        cout << endl;
    }
};

int main(int argc, char *argv[])
{
    BinarySearchTree<int> t;
    t.insert(5);
    t.insert(7);
    t.insert(5);
    t.insert(1);
    t.insert(3);
    t.insert(6);
    t.insert(9);

    t.dump();
    cout << t.search(2) << endl;
    cout << t.search(6) << endl;
    cout << t.search(4) << endl;

    cout << t.remove(5) << endl;
    t.dump();
    cout << t.remove(4) << endl;

    return 0;
}
