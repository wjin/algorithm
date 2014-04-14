// io
#include <iostream>
#include <fstream>
#include <sstream>
#include <streambuf>

// c headers
#include <cctype>
#include <cerrno>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

// stl
#include <vector>
#include <string>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
#include <forward_list>
#include <array>
#include <unordered_set>
#include <unordered_map>

// exception and limits
#include <exception>
#include <stdexcept>
#include <limits>
#include <climits>

using namespace std;

/* Question:
 *
 * Get the max difference between any two nodes in the given array.
 */

// segment tree
// use binary chained list to store it
class SegmentTree
{
private:
    // tree node
    struct TreeNode {
        TreeNode *lChild, *rChild;

        int left; // segment's left point
        int right; // segment's right point

        // here we can recode anything correponding to specific problem
        // i.e.: sum, max or min element, and so on
        int minEle; // max element in the scope[left...right]
        int maxEle; // min element in the scope[left...right]
        TreeNode(const int l = 0, const int r = 0):
            lChild(nullptr), rChild(nullptr), left(l), right(r), minEle(0), maxEle(0) {}
    };

    TreeNode *root;

    // build binary tree
    TreeNode* build(vector<int> &data, int left, int right)
    {
        // set segment's start and end point
        TreeNode *root = new TreeNode(left, right);
        if (root == nullptr) throw runtime_error("no memory");

        if (left == right) {
            root->minEle = root->maxEle = data[left];
            return root;
        }

        // build left and right tree recursively
        int mid = left + ((right - left) >> 1);
        root->lChild = build(data, left, mid);
        root->rChild = build(data, mid + 1, right);

        // update info
        root->minEle = min(root->lChild->minEle, root->rChild->minEle);
        root->maxEle = max(root->lChild->maxEle, root->rChild->maxEle);

        return root;
    }

    void query(TreeNode *t, int left, int right, int &lower, int &upper)
    {
        if (t == nullptr) return; // not happen
        if (t->left == left && t->right == right) {
            lower = min(lower, t->minEle);
            upper = max(upper, t->maxEle);
            return;
        }

        int mid = t->left + ((t->right - t->left) >> 1);
        if (left > mid) query(t->rChild, left, right, lower, upper); // search right child
        else if (right <= mid) query(t->lChild, left, right, lower, upper); // search left child
        else {
            query(t->lChild, left, mid, lower, upper);
            query(t->rChild, mid + 1, right, lower, upper);
        }
    }

public:
    SegmentTree(vector<int> &v)
    {
        root = build(v, 1, v.size() - 1);
    }

    int maxDiff(int left, int right)
    {
        int maxData = INT_MIN, minData = INT_MAX;
        query(root, left, right, minData, maxData);
        return maxData - minData;
    }
};

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    // freopen("output","w",stdout);
#endif

    int n, q;
    int a, b;
    cin >> n >> q;
    vector<int> v(n+1);

    for (int i = 1; i <= n; i++) cin >> v[i];
    SegmentTree sol(v);

    while (cin >> a >> b) {
        cout << sol.maxDiff(a, b) << endl;
    }

    return 0;
}
