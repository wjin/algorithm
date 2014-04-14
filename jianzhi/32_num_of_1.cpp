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
    int vecToNum(vector<int> &v, int start)
    {
        int ret = 0;
        for (size_t i = start; i < v.size(); i++) {
            ret = ret * 10 + v[i];
        }
        return ret;
    }

    vector<int> numToVec(int num)
    {
        vector<int> ret;
        int remain = 0;
        while (num) {
            remain = num % 10;
            ret.insert(ret.begin(), remain);
            num /= 10;
        }

        return ret;
    }

    int count(vector<int> &v)
    {
        int len = v.size();

        if (len == 0) return 0;
        if (len == 1) {
            return v[0] == 0 ? 0 : 1;
        }

        int first = v[0];
        int numFirst = 0;
        if (first > 1) {
            numFirst = pow(10, len - 1);
        } else if (first == 1) { // first == 1
            numFirst = vecToNum(v, 1) + 1;
        }

        int numOther = first * (len - 1) * pow(10, len - 2);

        v.erase(v.begin());
        int numRec = count(v);

        return numFirst + numOther + numRec;
    }

public:
    int count(int num)
    {
        vector<int> v = numToVec(num);
        return count(v);
    }
};

// brute force
class Solution2
{
    int countNum(int n)
    {
        int cnt = 0;
        while (n) {
            if (n % 10 == 1)
                cnt++;
            n /= 10;
        }
        return cnt;
    }

public:
    int count(int num)
    {
        int cnt = 0;
        for (int i = 1; i <= num; i++) {
            cnt += countNum(i);
        }
        return cnt;
    }
};

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    // freopen("output","w",stdout);
#endif

    Solution sol;
    int a, b;
    int num = 0;

    while (cin >> a >> b) {
        if (a > b) { // OJ input data.............
            swap(a, b);
        }

        if (a == 0) {
            num = sol.count(b);
        } else {
            num = sol.count(b) - sol.count(a - 1);
        }

        cout << num << endl;
    }

    Solution2 sol2;
    for (int i = 1; i < 10000; i++) {
        if (sol.count(i) != sol2.count(i)) cout << "fuck" << endl;
    }

    return 0;
}
