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

// segment tree (interval tree)
// use array to store it
class SegmentTree
{
private:
    // tree node
    struct TreeNode {
        int left; // segment's left point
        int right; // segment's right point

        // here we can recode anything correponding to specific problem
        // i.e.: sum, max or min element, and so on
        int minEle; // max element in the scope[left...right]
        int maxEle; // min element in the scope[left...right]
        TreeNode(): left(0), right(0), minEle(0), maxEle(0) {}
    };

    vector<TreeNode> treeNode; // tree node set, treeNode[1] is root

    // build perfect binary tree
    // using array(treeNode) to store it
    void build(vector<int> &data, int t, int left, int right)
    {
        // set segment's start and end point
        treeNode[t].left = left;
        treeNode[t].right = right;

        if (left == right) {
            treeNode[t].minEle = treeNode[t].maxEle = data[left];
            return;
        }

        // build left and right tree recursively
        int mid = left + ((right - left) >> 1);
        int leftRoot = t * 2;
        int rightRoot = leftRoot + 1;
        build(data, leftRoot, left, mid);
        build(data, rightRoot, mid + 1, right);

        // update info
        treeNode[t].minEle = min(treeNode[leftRoot].minEle, treeNode[rightRoot].minEle);
        treeNode[t].maxEle = max(treeNode[leftRoot].maxEle, treeNode[rightRoot].maxEle);
    }

    void query(int t, int left, int right, int &lower, int &upper)
    {
        if (treeNode[t].left == left && treeNode[t].right == right) {
            lower = min(lower, treeNode[t].minEle);
            upper = max(upper, treeNode[t].maxEle);
            return;
        }

        int mid = treeNode[t].left + ((treeNode[t].right - treeNode[t].left) >> 1);
        if (left > mid) query(2 * t + 1, left, right, lower, upper); // search right child
        else if (right <= mid) query(2 * t, left, right, lower, upper); // search left child
        else {
            query(2 * t, left, mid, lower, upper);
            query(2 * t + 1, mid + 1, right, lower, upper);
        }
    }

public:
    // 2 * n is enough to store the tree with n leafes
    SegmentTree(vector<int> &v) : treeNode(v.size() * 2)
    {
        build(v, 1, 1, v.size() - 1);
    }

    int maxDiff(int left, int right)
    {
        int maxData = INT_MIN, minData = INT_MAX;
        query(1, left, right, minData, maxData);
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
