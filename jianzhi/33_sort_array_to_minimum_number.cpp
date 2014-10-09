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
    static bool func(string s1, string s2)
    {
        string t1(s1 + s2);
        string t2(s2 + s1);
        return t1 < t2;
    }

public:
    string getMaxNum(vector<string> &v)
    {
        stringstream ss;

        sort(v.begin(), v.end(), func);
        for (size_t i = 0; i < v.size(); i++)
            ss << v[i];

        string ret;
        ss >> ret;
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
    int m, t;
    vector<string> num;

    while (cin >> m) {
        num.clear();
        for (int i = 0; i < m ; i++) {
            cin >> t;
            num.push_back(to_string(t));
        }
        cout << sol.getMaxNum(num) << endl;
    }

    return 0;
}
