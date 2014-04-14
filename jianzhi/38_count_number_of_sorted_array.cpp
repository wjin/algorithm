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
//#define CPP11
#ifdef CPP11
#include <forward_list>
#include <array>
#include <unordered_set>
#include <unordered_map>
#endif

// exception and limits
#include <exception>
#include <stdexcept>
#include <limits>
#include <climits>
#include <utility>

using namespace std;

class Solution
{
private:
    // return max pos such that v[i] == target
    int upper_bound(vector<int> &v, int target)
    {
        int low = 0, high = v.size() - 1;
        int mid = 0;
        while (low <= high) { // =
            mid = low + (high - low) / 2; // be careful about overflow
            if (v[mid] == target) {
                if (v[high] == target) // judge it here
                    return high;
                else { // update search bound
                    low = mid;
                    high -= 1;
                }
            } else if (v[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }

    // return min pos such that v[i] == target
    int lower_bound(vector<int> &v, int target)
    {
        int low = 0, high = v.size() - 1;
        int mid = 0;
        while (low <= high) { // =
            mid = low + (high - low) / 2; // be careful about overflow
            if (v[mid] == target) {
                if (v[low] == target)
                    return low;
                else { // update search bound
                    low += 1;
                    high = mid;
                }
            } else if (v[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }

public:
    int count(vector<int> &v, int target)
    {
        int low = lower_bound(v, target);
        if (low == -1) return 0;
        int high = upper_bound(v, target);

        return high - low + 1;
    }
};

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    // freopen("output","w",stdout);
#endif

    Solution sol;
    int n, m, target;
    vector<int> v;

#if 0
    // using stream cannot pass OJ :(
    while (cin >> n) {
        v.clear();
        v.resize(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        cin >> m;
        while (m--) {
            cin >> target;
            cout << sol.count(v, target) << endl;
        }
    }
#endif

#if 1
    while (scanf("%d", &n) != EOF) {
        v.clear();
        v.resize(n);
        for (int i = 0; i < n; i++)
            scanf("%d", &v[i]);
        scanf("%d", &m);
        while (m--) {
            scanf("%d", &target);
            cout << sol.count(v, target) << endl;
        }
    }
#endif
    return 0;
}
