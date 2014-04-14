/*

 Palindrome Partitioning

 Given a string s, partition s such that every substring of the partition is a palindrome.

 Return all possible palindrome partitioning of s.

 For example, given s = "aab",
 Return

 [
 ["aa","b"],
 ["a","a","b"]
 ]

 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    // judge whether a substring(start...end) of s is a palindrome
    bool isPalindrome(string &s, int start, int end)
    {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    void dfs(string &s, vector<vector<string> > &res, int start,
             vector<string> &cur)
    {
        if (start == s.size()) {
            res.push_back(cur);
        } else {
            for (int i = start; i < s.size(); i++) {
                if (isPalindrome(s, start, i)) {
                    cur.push_back(s.substr(start, i - start + 1));
                    dfs(s, res, i + 1, cur);
                    cur.pop_back();
                }
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> res;
        vector<string> cur;
        dfs(s, res, 0, cur);
        return res;
    }
};

int main(int argc, char* argv[])
{
    Solution sol;
    string s("aab");

    vector<vector<string> > res;
    res = sol.partition(s);

    for (auto &t1 : res) {
        for (auto t2 : t1)
            cout << t2 << ends;
        cout << endl;
    }

    return 0;
}
