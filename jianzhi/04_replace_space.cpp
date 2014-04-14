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
public:
#if 0
    string replace_char(string s)
    {
        vector<char> v;
        for (auto c : s) {
            if (c == ' ') {
                v.push_back('%');
                v.push_back('2');
                v.push_back('0');
            } else {
                v.push_back(c);
            }
        }

        return string(v.begin(), v.end());
    }
#endif

    void replace_char_inplace(string &s)
    {
        int spaceCnt = 0;
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                ++spaceCnt;
            }
        }

        if (spaceCnt == 0) return;

        int origSize = s.size();
        int newSize = origSize + spaceCnt * 2;
        s.resize(newSize);

        for (int i = origSize - 1, j = newSize - 1; i >= 0 && i < j; i--, j--) {
            if (s[i] == ' ') {
                s[j--] = '0';
                s[j--] = '2';
                s[j] = '%';
            } else {
                s[j] = s[i];
            }
        }
    }
};

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    // freopen("output","w",stdout);
#endif

    Solution sol;
    string str;

    while (getline(cin, str)) {
        sol.replace_char_inplace(str);
        cout << str << endl;
    }

    return 0;
}
