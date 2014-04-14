/*

 Word Break

 Given a string s and a dictionary of words dict, determine if s can be segmented into a
 space-separated sequence of one or more dictionary words.

 For example, given
 s = "leetcode",
 dict = ["leet", "code"].

 Return true because "leetcode" can be segmented as "leet code".

 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    // brute force; cannot psss OJ
    bool wordBreak1(string s, unordered_set<string> &dict)
    {
        if (s.empty())
            return true; //
        for (size_t i = 0; i < s.length(); i++) {
            if (dict.find(s.substr(0, i + 1)) != dict.end()
                    && wordBreak1(s.substr(i + 1), dict))
                return true;
        }
        return false;
    }

    // dp
    bool wordBreak2(string s, unordered_set<string> &dict)
    {
        vector<bool> dp(s.length() + 1, false);
        dp[0] = true;
        for (size_t i = 1; i <= s.length(); i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] == true
                        && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break; //
                }
            }
        }
        return dp[s.length()];
    }

    // dfs with cache, fast, can pass OJ
    bool dfs(string s, unordered_set<string> &dict, unordered_map<string, bool> &cache)
    {
        if (s.empty())
            return true;

        if (cache.count(s) == 1) return cache[s];

        for (size_t i = 0; i < s.length(); i++) {
            if (dict.find(s.substr(0, i + 1)) != dict.end()
                    && dfs(s.substr(i + 1), dict, cache)) {
                cache[s] = true;
                return true;
            }
        }

        cache[s] = false;
        return false;
    }
    bool wordBreak3(string s, unordered_set<string> &dict)
    {
        unordered_map<string, bool> cache;
        return dfs(s, dict, cache);
    }
};

int main(int argc, char* argv[])
{
    string s1("leetcode");
    unordered_set<string> dict1 = { "leet", "code" };

    string s2("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
              "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"
              "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab");
    unordered_set<string> dict2 = { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa",
                                    "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa"
                                  };

    Solution sol;
    cout << sol.wordBreak1(s1, dict1) << endl;
    cout << sol.wordBreak2(s1, dict1) << endl;
    cout << sol.wordBreak3(s1, dict1) << endl;

    //cout << sol.wordBreak1(s2, dict2) << endl;
    cout << sol.wordBreak2(s2, dict2) << endl;
    cout << sol.wordBreak3(s2, dict2) << endl;

    return 0;
}
