/*

 Wildcard Matching

 Implement wildcard pattern matching with support for '?' and '*'.

 '?' Matches any single character.
 '*' Matches any sequence of characters (including the empty sequence).

 The matching should cover the entire input string (not partial).

 The function prototype should be:
 bool isMatch(const char *s, const char *p)

 Some examples:
 isMatch("aa","a") → false
 isMatch("aa","aa") → true
 isMatch("aaa","aa") → false
 isMatch("aa", "*") → true
 isMatch("aa", "a*") → true
 isMatch("ab", "?*") → true
 isMatch("aab", "c*a*b") → false

 */

#include <iostream>
using namespace std;

class Solution
{
public:
    bool isMatch(const char *s, const char *p)
    {
        if (s == nullptr && p == nullptr)
            return true;
        if (s == nullptr || p == nullptr)
            return false;

        const char* star = nullptr;
        const char* lastPos = nullptr;

        while (*s) {
            // equal, continue
            if (*s == *p || *p == '?') {
                s++;
                p++;
                continue;
            }

            // first time encounter star
            // keep star position and s position
            // let star stands for zero char and continue comparison
            if (*p == '*') {
                star = p;
                lastPos = s;
                p++;
                continue;
            }

            // if mismatch, find previous star if exist
            // and let s + 1, which means star stands for one more char in s
            // reset p to continue comparison
            if (star) {
                s = ++lastPos;
                p = star + 1;
                continue;
            }

            // mismatch
            return false;
        }

        // when get to the end of s
        // guarantee p has only * in the end
        while (*p == '*')
            p++;
        return !*p;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    cout << sol.isMatch("aa", "a") << endl;
    cout << sol.isMatch("aa", "aa") << endl;
    cout << sol.isMatch("aaa", "aa") << endl;
    cout << sol.isMatch("aa", "*") << endl;
    cout << sol.isMatch("aa", "a*") << endl;
    cout << sol.isMatch("ab", "?*") << endl;
    cout << sol.isMatch("aab", "c*a*b") << endl;

    return 0;
}
