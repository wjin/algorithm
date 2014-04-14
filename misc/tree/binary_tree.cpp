#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <tuple>

using namespace std;

// forward declaration binary tree
template<typename T>
class BiTree;

// binary tree node
template<typename T>
class BiTreeNode
{
public:
    friend class BiTree<T> ;
    BiTreeNode(T data, BiTreeNode *l = nullptr, BiTreeNode *r = nullptr) :
        m_data(data), left(l), right(r)
    {
    }

private:
    T m_data;
    BiTreeNode *left, *right;
};

// binary tree node with parent pointer
template<typename T>
class BiTreeNodeWithParent: private BiTreeNode<T> // private inheritance
{
public:
    friend class BiTree<T> ;
    BiTreeNodeWithParent(T data, BiTreeNode<T> *p = nullptr,
                         BiTreeNode<T> *l = nullptr, BiTreeNode<T> *r = nullptr) :
        BiTreeNode<T>(data, l, r), parent(p)
    {
    }

private:
    BiTreeNode<T> *parent;
};

// binary tree
template<typename T>
class BiTree
{
public:
    BiTree(BiTreeNode<T> *t = nullptr) :
        root(t)
    {
    }

    ~BiTree()
    {
        destroy(root);
    }

    void Initialize(string s)
    {
        int idx = 0;
        root = do_CreateTree(s, idx);
    }

    void PreOrder()
    {
        do_PreOrder(root);
    }

    void InOrder()
    {
        do_InOrder(root);
    }

    void PostOrder()
    {
        do_PostOrder(root);
    }

    void PreOrderUnRec()
    {
        stack<BiTreeNode<T>*> s;
        BiTreeNode<T> *p = root;

        while (p || !s.empty()) {
            if (p) {
                handle_data(p);
                s.push(p);
                p = p->left;
            } else {
                p = s.top();
                s.pop();
                p = p->right;
            }
        }
    }

    void PreOrderUnRec2()
    {
        stack<BiTreeNode<T>*> s;
        BiTreeNode<T> *p = root;

        if (p == NULL)
            return;
        else
            s.push(p);

        while (!s.empty()) {
            p = s.top();
            s.pop();
            handle_data(p);
            if (p->right != NULL)
                s.push(p->right);
            if (p->left != NULL)
                s.push(p->left);
        }
    }

    void InOrderUnRec()
    {
        stack<BiTreeNode<T>*> s;
        BiTreeNode<T> *p = root;

        while (p || !s.empty()) {
            if (p) {
                s.push(p);
                p = p->left;
            } else {
                p = s.top();
                s.pop();
                handle_data(p);
                p = p->right;
            }
        }
    }

    void PostOrderUnRec()
    {
        stack<BiTreeNode<T>*> s;
        BiTreeNode<T> *p = root;
        BiTreeNode<T> *prev = nullptr; // previous handled node

        while (p || !s.empty()) {
            if (p) {
                s.push(p);
                p = p->left;
            } else {
                p = s.top();
                if (p->right && p->right != prev) {
                    p = p->right;
                    s.push(p);
                    p = p->left;
                } else {
                    s.pop();
                    handle_data(p);
                    prev = p; //
                    p = nullptr;
                }
            }
        }
    }

    // Morris algorithm:
    // time complexity: O(n)
    // space complexity: O(1)
    void PreOrderMorris()
    {
        BiTreeNode<T> *cur = root, *p = nullptr; // cur's left
        while (cur) {
            if (cur->left == nullptr) {
                handle_data(cur);
                cur = cur->right;
            } else {
                // find sucessor for the cur's left child's rightmost node
                p = cur->left; // cur's left
                while (p->right && p->right != cur) p = p->right; // rightmost

                if (!p->right) { // not threaded
                    p->right = cur; // thread it

                    // hadle current node and forward to left child
                    handle_data(cur);
                    cur = cur->left;
                } else { // node has already been threaded
                    p->right = nullptr; // delete it
                    cur = cur->right; // forward to right child
                }
            }
        }
    }

    void InOrderMorris()
    {
        BiTreeNode<T> *cur = root, *p = nullptr; // cur's left
        while (cur) {
            if (cur->left == nullptr) {
                handle_data(cur);
                cur = cur->right;
            } else {
                // find sucessor for the cur's left child's rightmost node
                p = cur->left; // cur's left
                while (p->right && p->right != cur) p = p->right; // rightmost

                if (!p->right) { // not threaded
                    p->right = cur; // thread it
                    cur = cur->left; // forward to left
                } else { // node has already been threaded
                    // hadle current node
                    handle_data(cur);

                    p->right = nullptr; // delete it
                    cur = cur->right; // forward to right child
                }
            }
        }
    }

    void LevelOrder()
    {
        queue<BiTreeNode<T>*> q;
        BiTreeNode<T> *p = root;

        if (p == NULL)
            return;
        else
            q.push(p);

        while (!q.empty()) {
            p = q.front();
            q.pop();
            handle_data(p);
            if (p->left != NULL)
                q.push(p->left);
            if (p->right != NULL)
                q.push(p->right);
        }
    }

    // output pre-order with directory style
    void PreOrderDir()
    {
        do_PreOrderDir(root, 0);
    }

    int CountLeaf()
    {
        return do_CountLeaf(root);
    }

    int Height()
    {
        return do_Height(root);
    }

    // calculate level max nodes
    int LevelMaxNode()
    {
        int maxNode = 0;
        queue<BiTreeNode<T>*> q;
        BiTreeNode<T>* p = root;

        if (p == NULL)
            return 0;
        else
            q.push(p);

        int curLevelNode = 0;
        while (!q.empty()) {
            curLevelNode = q.size();
            maxNode = max(curLevelNode, maxNode);

            while (curLevelNode) {
                p = q.front();
                q.pop();

                if (p->left)
                    q.push(p->left);
                if (p->right)
                    q.push(p->right);
                curLevelNode--;
            }
        }

        return maxNode;
    }

    tuple<int, int, int> CountNodeDegree()
    {
        int d1 = 0, d2 = 0, d3 = 0;
        do_CountNodeDegree(root, d1, d2, d3);
        return make_tuple(d1, d2, d3);
    }

private:
    BiTreeNode<T> *root;

    // create tree recursively with pre-order.
    // s[i] == '#' means this sub tree is null.
    // we can create a test tree by means of it quickly.
    BiTreeNode<T>* do_CreateTree(string s, int &idx)
    {
        if (s[idx] == '#')
            return nullptr;
        else {
            BiTreeNode<T> *t = new BiTreeNode<T>(s[idx]);
            t->left = do_CreateTree(s, ++idx);
            t->right = do_CreateTree(s, ++idx);

            return t;
        }
    }

    void destroy(BiTreeNode<T> *t)
    {
        if (t != NULL) {
            if (t->left)
                destroy(t->left);
            if (t->right)
                destroy(t->right);
            delete t;
        }
    }

    void handle_data(BiTreeNode<T> *t)
    {
        cout << t->m_data << "-->";
    }

    void do_PreOrder(BiTreeNode<T> *t)    // recursive pre-order traverse tree
    {
        if (t) {
            handle_data(t);
            do_PreOrder(t->left);
            do_PreOrder(t->right);
        }
    }

    void do_InOrder(BiTreeNode<T> *t)    // recursive in-order traverse tree
    {
        if (t) {
            do_PreOrder(t->left);
            handle_data(t);
            do_PreOrder(t->right);
        }
    }

    void do_PostOrder(BiTreeNode<T> *t)    // recursive post-order traverse tree
    {
        if (t) {
            do_PostOrder(t->left);
            do_PostOrder(t->right);
            handle_data(t);
        }
    }

    void do_PreOrderDir(BiTreeNode<T>* t, int dir)
    {
        if (t) {
            for (int i = dir; i > 0; i--)
                cout << ' ';
            cout << t->m_data << endl;
        }

        if (t->left) {
            do_PreOrderDir(t->left, dir + 1);
        }

        if (t->right) {
            do_PreOrderDir(t->right, dir + 1);
        }
    }

    int do_CountLeaf(BiTreeNode<T>* t)
    {
        if (t == NULL)
            return 0;
        else if (t->left == NULL && t->right == NULL)
            return 1;
        else
            return do_CountLeaf(t->left) + do_CountLeaf(t->right);
    }

    int do_Height(BiTreeNode<T>* t)
    {
        if (t == NULL)
            return 0;
        else {
            int leftHeight = do_Height(t->left);
            int rightHeight = do_Height(t->right);
            return 1 + max(leftHeight, rightHeight);
        }
    }

    void do_CountNodeDegree(BiTreeNode<T>* t, int &d1, int &d2, int &d3)
    {
        if (t) {
            if (t == root) { // be careful as root has no in-degree
                if (t->left && t->right)
                    d2++;
                else if (t->left || t->right)
                    d1++;
            } else if (t->left == NULL && t->right == NULL)
                d1++;
            else if (t->left == NULL || t->right == NULL)
                d2++;
            else
                d3++;

            do_CountNodeDegree(t->left, d1, d2, d3);
            do_CountNodeDegree(t->right, d1, d2, d3);
        }
    }
};

int longestpath()
{
    return 1;
}

int main()
{
    /*
     *   Test  Tree
     *
                   A
                 /   \
                B     F
               / \    /
              C   D   G
                 /     \
                E       H
     */
    // preorder of tree node, # means nullptr
    string s("ABC##DE###FG#H###");

    BiTree<char> t;

    cout << "create tree......." << endl;
    t.Initialize(s);

    cout << "PreOrder: ";
    t.PreOrder();
    cout << endl;

    cout << "PreOrderMorris: ";
    t.PreOrderMorris();
    cout << endl;

    cout << "PreOrderUnRec: ";
    t.PreOrderUnRec();
    cout << endl;

    cout << "PreOrderUnRec2: ";
    t.PreOrderUnRec2();
    cout << endl;

    cout << "InOrder: ";
    t.InOrder();
    cout << endl;

    cout << "InOrderUnRec: ";
    t.InOrderUnRec();
    cout << endl;

    cout << "InOrderMorris: ";
    t.InOrderMorris();
    cout << endl;

    cout << "PostOrder: ";
    t.PostOrder();
    cout << endl;

    cout << "PostOrderUnRec: ";
    t.PostOrderUnRec();
    cout << endl;

    cout << "LevelOrder: ";
    t.LevelOrder();
    cout << endl;

    cout << "CountLeaf: " << t.CountLeaf() << endl;

    cout << "Height: " << t.Height() << endl;

    cout << "LevelMaxNode: " << t.LevelMaxNode() << endl;

    tuple<int, int, int> tup = t.CountNodeDegree();
    cout << "CountNodeDegree: " << get<0>(tup) << ends << get<1>(tup) << ends << get<2>(tup) << endl;

    t.PreOrderDir();

    return 0;
}
