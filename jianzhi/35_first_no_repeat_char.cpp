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
    const int charMax;

public:
    Solution(const int x = 256) : charMax(x)
    {
    }

    int firstNoRepeat(string &s)
    {
        vector<int> v(charMax, 0);

        for (size_t i = 0; i < s.size(); i++) {
            v[s[i]]++;
        }

        for (size_t i = 0; i < s.size(); i++)
            if (v[s[i]] == 1) return i;

        return -1;
    }
};

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    // freopen("output","w",stdout);
#endif

    Solution sol;
    string s;

    while (cin >> s) {
        cout << sol.firstNoRepeat(s) << endl;
    }

    return 0;
}
