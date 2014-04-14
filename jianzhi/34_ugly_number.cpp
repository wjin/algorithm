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
    vector<int> v;
    const int uglyMax;

    void initialUglyNUmber()
    {
        v[0] = 1; //first number

        int last2 = 0;
        int last3 = 0;
        int last5 = 0;
        int next = 0;

        for (int i = 1; i < uglyMax; i++) {
            // OJ complier does not support c++ 11 initializer list
            next = min(v[last2] * 2, min(v[last3] * 3, v[last5] * 5));
            v[i] = next;

            while (v[last2] * 2 <= next) last2++; // =
            while (v[last3] * 3 <= next) last3++;
            while (v[last5] * 5 <= next) last5++;
        }
    }

public:
    Solution(const int x = 1500) : uglyMax(x)
    {
        v.resize(uglyMax);
        initialUglyNUmber();
    }

    int getUglyNumber(int n)
    {
        if (n < 1) return -1;
        return v[n - 1];
    }
};

// priority queue solution
class Solution2
{
private:
    vector<int> v; // store ugly number
    const int uglyMax;
    typedef pair<int, int> node;
    priority_queue<node, vector<node>, greater<node>> q; // little heap

    void initialUglyNUmber()
    {
        q.push(make_pair(1, 2)); // initial queue element
        for (int i = 0; i < uglyMax; i++) {
            node t = q.top();
            q.pop();
            switch (t.second) {
            case 2:
                q.push(make_pair(t.first * 2, 2)); // no break
            case 3:
                q.push(make_pair(t.first * 3, 3));
            case 5:
                q.push(make_pair(t.first * 5, 5));
            }
            v[i] = t.first; // get one ugly number
        }
    }

public:
    Solution2(const int x = 1500) : uglyMax(x)
    {
        v.resize(uglyMax);
        initialUglyNUmber();
    }

    int getUglyNumber(int n)
    {
        if (n < 1) return -1;
        return v[n - 1];
    }
};


int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    // freopen("output","w",stdout);
#endif

    Solution2 sol;
    int n;

    while (cin >> n) {
        cout << sol.getUglyNumber(n) << endl;
    }

    return 0;
}
