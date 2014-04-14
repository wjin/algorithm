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

using namespace std;

class Solution
{
private:
    vector<int> m_copy; // extra space

    void merge(vector<int> &v, int start, int middle, int end, long long &ret)
    {
        int i = middle, j = end;
        int k = end;

        // copy data to assistant array first
        copy(v.begin() + start, v.begin() + end + 1, m_copy.begin() + start);

        while (i >= start && j >= middle + 1) {
            if (m_copy[i] <= m_copy[j]) // =
                v[k--] = m_copy[j--];
            else { // v[i] > v[j], inverse pair
                ret += (j - middle);
                v[k--] = m_copy[i--];
            }
        }

        /* no need to copy here as
        while (i >= start)
            m_copy[k--] = v[i--];
        */

        while (j >= middle + 1)
            v[k--] = m_copy[j--];
    }

    void sort(vector<int> &v, int start, int end, long long &ret)
    {
        if (start < end) {
            int middle = start + ((end - start) >> 1);
            sort(v, start, middle, ret);
            sort(v, middle + 1, end, ret);
            merge(v, start, middle, end, ret);
        }
    }

public:
    long long inversePair(vector<int> &v) // long long to avoid OJ overflow
    {
        m_copy.clear();
        m_copy.resize(v.size());

        long long ret = 0; //
        sort(v, 0, v.size() - 1, ret);
        return ret;
    }
};

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    // freopen("output","w",stdout);
#endif

    Solution sol;
    int n;
    vector<int> v;

    while (cin >> n) {
        v.clear();
        v.resize(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];

        cout << sol.inversePair(v) << endl;
    }

    return 0;
}

