/*

 Longest Palindromic Substring

 Given a string S, find the longest palindromic substring in S.
 You may assume that the maximum length of S is 1000, and there exists
 one unique longest palindromic substring.

 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// time complexity: O(n^2)
// space complexity: O(n^2), can optimize to O(n)
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int len = s.size();
        if (len == 0)
            return "";

        vector<vector<bool>> dp(len, vector<bool>(len, false));
        int subStrLen = 0, start = 0;

        // dp[i][j] is true means s[i]...s[j] is palindrome
        for (int col = 0; col < len; col++) {
            for (int row = 0; row <= col; row++) {
                if (row == col) { // single char is palindrome
                    dp[row][col] = true;
                    if (col - row + 1 > subStrLen) { // update the longest candidate
                        subStrLen = col - row + 1;
                        start = row;
                    }
                } else if (s[row] == s[col]) {
                    // short circuit evaluation
                    // row + 1 == col means only have two letters, be careful
                    if (row + 1 == col || dp[row + 1][col - 1]) {
                        dp[row][col] = true;
                        if (col - row + 1 > subStrLen) {  // update the longest candidate
                            subStrLen = col - row + 1;
                            start = row;
                        }
                    }
                }
            }
        }

        return s.substr(start, subStrLen);
    }
};

// time complexity: O(n)
// space complexity: O(n)
// http://leetcode.com/2011/11/longest-palindromic-substring-part-ii.html
class Solution2
{
private:
    string preProcess(const string &s)
    {
        string ret("^"); // leading with special character

        // insert delimeter
        for (auto e : s) {
            ret += '#';
            ret += e;
        }
        ret += "#$"; // ending with $
        return ret;
    }
public:
    string longestPalindrome(string s)
    {
        string t(preProcess(s));
        int len = t.size();
        vector<int> p(len, 0);

        // calculate array p[i]
        // p[i] means how long it can be extended to left or right to form a palindrome
        // centered with i, character i itself is included in this length.
        // i.e.: p[i] = 2, means  p[i-1] p[i] p[i+1] is a palindrome
        // p[i] - 1 is the palindroem length of original string
        int id = 0, mx = 0;
        for (int i = 1; i < len - 1; i++) {
            p[i] = (mx > i) ? min(p[2 * id - i], mx - i) : 1;
            while (t[i + p[i]] == t[i - p[i]]) p[i]++;

            if (p[i] + i > mx) {
                id = i;
                mx = p[i] + i;
            }
        }

        int maxLenId = 1;
        for (int i = 1; i < len; i++) {
            if (p[i] > p[maxLenId]) {
                maxLenId = i;
            }
        }
        // be careful with substr start point
        return s.substr((maxLenId - p[maxLenId] ) / 2, p[maxLenId] - 1);
    }
};

// time complexity: O(n^2)
// space complexity: O(1)
class Solution3
{
private:
    string expandAroundCenter(string s, int c1, int c2)
    {
        int l = c1, r = c2;
        int n = s.length();
        while (l >= 0 && r <= n - 1 && s[l] == s[r]) {
            l--;
            r++;
        }
        return s.substr(l + 1, r - l - 1);
    }

public:
    string longestPalindrome(string s)
    {
        int n = s.length();
        if (n == 0) return "";

        string longest = s.substr(0, 1);  // a single char itself is a palindrome

        for (int i = 0; i < n - 1; i++) {
            string p1 = expandAroundCenter(s, i, i); // odd
            if (p1.length() > longest.length())
                longest = p1;

            string p2 = expandAroundCenter(s, i, i+1); // even
            if (p2.length() > longest.length())
                longest = p2;
        }

        return longest;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    Solution2 sol2;
    Solution3 sol3;
    string s1;
    string s2("a");
    string s3("aba");
    string s4("abcc");

    cout << sol.longestPalindrome(s1) << endl;
    cout << sol.longestPalindrome(s2) << endl;
    cout << sol.longestPalindrome(s3) << endl;
    cout << sol.longestPalindrome(s4) << endl;

    cout << sol2.longestPalindrome(s1) << endl;
    cout << sol2.longestPalindrome(s2) << endl;
    cout << sol2.longestPalindrome(s3) << endl;
    cout << sol2.longestPalindrome(s4) << endl;

    cout << sol3.longestPalindrome(s1) << endl;
    cout << sol3.longestPalindrome(s2) << endl;
    cout << sol3.longestPalindrome(s3) << endl;
    cout << sol3.longestPalindrome(s4) << endl;

    return 0;
}
