/*

1.3

Given two strings, write a method to decide if one is a permutation of the other

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Solution
{
public:
    // sort will change the original string
    // and it is a little slow
    bool isAnagram(string &s1, string &s2)
    {
        if (s1.length() != s2.length()) return false;

        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
};

class Solution2
{
public:
    // hash
    bool isAnagram(string &s1, string &s2)
    {
        if (s1.length() != s2.length()) return false;

        vector<int> cnt(CHAR_MAX, 0);

        for (auto c : s1) {
            cnt[c]++;
        }

        for (auto c : s2) {
            if (--cnt[c] < 0) return false;
        }

        return true;
    }
};

int main()
{
    Solution sol1;
    Solution2 sol2;

    string s1("aba c");
    string s2("baac ");
    string s3("aba d");

    cout << sol2.isAnagram(s1, s2) << endl;
    cout << sol1.isAnagram(s1, s2) << endl;

    cout << sol2.isAnagram(s1, s3) << endl;
    cout << sol1.isAnagram(s1, s3) << endl;

    return 0;
}
