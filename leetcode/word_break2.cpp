/*

 Word Break ||

 Given a string s and a dictionary of words dict, add spaces in s to
 construct a sentence where each word is a valid dictionary word.

 Return all such possible sentences.

 For example, given
 s = "catsanddog",
 dict = ["cat", "cats", "and", "sand", "dog"].

 A solution is ["cats and dog", "cat sand dog"].

 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    // dp and store all previous nodes which make dp[i] == true,
    // so that we can use them to construct string later
    vector<vector<int>> get_break_arrays(string &s,
                                         unordered_set<string> &dict)
    {
        int len = s.length();
        vector<bool> dp(len + 1, false);
        vector<vector<int>> prev(len + 1); // breakable chain
        dp[0] = true;

        for (int i = 1; i <= len; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] == true
                        && dict.find(s.substr(j, i - j)) != dict.end()) {
                    prev[i].push_back(j);
                    dp[i] = true;
                    // continue find all suitable previous nodes
                    // break;
                }
            }
        }

        return prev;
    }

    void construct_string(vector<vector<int>> &prev, string &s,
                          vector<string> &ret, int end, string cur)
    {
        for (int i = 0; i < prev[end].size(); i++) {
            int previous = prev[end][i];

            string tmp(s.substr(previous, end - previous));
            string tmpres;
            if (!tmp.empty() && !cur.empty())
                tmpres = tmp + ' ' + cur;
            else if (cur.empty()) {
                tmpres = tmp;
            }

            if (previous == 0) {
                ret.push_back(tmpres);
            } else {
                construct_string(prev, s, ret, previous, tmpres);
            }
        }
    }

    vector<string> wordBreak(string s, unordered_set<string> &dict)
    {
        vector<string> ret;
        vector<vector<int> > prev = get_break_arrays(s, dict);
        construct_string(prev, s, ret, s.length(), "");
        return ret;
    }
};

int main(int argc, char* argv[])
{
    string s("catsanddog");
    unordered_set<string> dict = { "cat", "cats", "and", "sand", "dog" };

    Solution sol;
    vector<string> ret = sol.wordBreak(s, dict);
    for (auto s : ret) {
        cout << s << endl;
    }

    return 0;
}
