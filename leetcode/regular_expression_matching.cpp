/*

 Regular Expression Matching

 Implement regular expression matching with support for '.' and '*'.

 '.' Matches any single character.
 '*' Matches zero or more of the preceding element.

 The matching should cover the entire input string (not partial).

 The function prototype should be:
 bool isMatch(const char *s, const char *p)

 Some examples:
 isMatch("aa","a") → false
 isMatch("aa","aa") → true
 isMatch("aaa","aa") → false
 isMatch("aa", "a*") → true
 isMatch("aa", ".*") → true
 isMatch("ab", ".*") → true
 isMatch("aab", "c*a*b") → true

 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    bool isMatch(const char *s, const char *p)
    {
        if (s == nullptr || p == nullptr) { // invalid
            return 0;
        }

        if (*p == 0) { // empty string
            return *s == 0;
        }

        // p + 1 is not asterisk, also note we can dereference p+1 validly
        if (*(p + 1) != '*') {
            // however, we need to check *s
            if (*s && (*p == *s || *p == '.'))
                return isMatch(s + 1, p + 1);
            return false;

        } else { // p + 1 is *
            //
            while (*s && (*s == *p || *p == '.')) {
                if (isMatch(s, p + 2))
                    return true;
                s++; // let * to be one more preceding char in p
            }
            // current char of s is not equal to p, delete it in p together with *
            return isMatch(s, p + 2);
        }
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    cout << sol.isMatch("aa", "a") << endl;
    cout << sol.isMatch("aa", "aa") << endl;
    cout << sol.isMatch("aaa", "aa") << endl;
    cout << sol.isMatch("aa", "a*") << endl;
    cout << sol.isMatch("ab", ".*") << endl;

    cout << sol.isMatch("", "***") << endl;
    cout << sol.isMatch("aab", "a*b*") << endl;
    cout << sol.isMatch("aab", "*a*b") << endl;
    cout << sol.isMatch("abcccccc", "abc*") << endl;

    cout << sol.isMatch("aab", "c*a*b") << endl;
    cout << sol.isMatch("aab", "x*y*c*a*b") << endl;

    cout << sol.isMatch("ab", ".*c") << endl;

    cout << sol.isMatch("aab", "x**y*c*a*b") << endl; // double * is invalid ?
}
