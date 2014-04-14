/*

 Distinct Subsequences

 Given a string S and a string T, count the number of distinct subsequences of T in S.

 A subsequence of a string is a new string which is formed from the original string
 by deleting some (can be none) of the characters without disturbing the relative positions
 of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

 Here is an example:
 S = "rabbbit", T = "rabbit"

 Return 3.

 */

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Time Limit Exceeded
class Solution
{
public:
    // ss: string s start; ts: string t start; te: string t end
    void dfs(string s, string t, int ss, int ts, int te, int &num)
    {
        if (ts == te) {
            num++;
        } else {
            for (int i = ss; i < s.size(); i++) {
                if (s[i] == t[ts])
                    dfs(s, t, i + 1, ts + 1, te, num);
            }
        }
    }

    int numDistinct(string S, string T)
    {
        if (S.empty() || T.empty())
            return 0;
        int num = 0;
        dfs(S, T, 0, 0, T.size(), num);
        return num;
    }
};

// dp
class Solution2
{
public:
    int numDistinct(string S, string T)
    {
        if (S.empty() || T.empty())
            return 0;

        int sLen = S.size(), tLen = T.size();

        // for each character in T, record its all positions in S
        vector<vector<int>> pos(tLen);
        for (int i = 0; i < tLen; i++) {
            for (int j = 0; j < sLen; j++) {
                if (T[i] == S[j])
                    pos[i].push_back(j);
            }
        }

        if (pos[0].empty()) return 0; // bug, case s3, t3

        // we can dfs above position table or use dp to accelerate search
        // the problem is equal to that: choose one number from each row,
        // keep it strictly ascending, how many ways we can get to the last row?
        vector<vector<int>> dp(tLen, vector<int>(sLen, 0));

        // initialize first line
        fill(dp[0].begin(), dp[0].end(), 1);

        for (int i = 1; i < tLen; i++) {
            for (int j = 0; j < pos[i].size(); j++) {

                // calculate dp[i][j]
                for (int k = 0; k < pos[i - 1].size(); k++) {
                    if (pos[i - 1][k] < pos[i][j]) // ascending...
                        dp[i][j] += dp[i - 1][k];
                    else
                        break;
                }
            }
        }

        // sum all results from last line
        return accumulate(dp[tLen - 1].begin(), dp[tLen - 1].end(), 0);
    }
};

// dp[i][j] means number of distinct subsequences for T[0...j] in S[0...i]
// dp[i][j] = dp[i-1][j]               ; not use S[i]
//          = dp[i-1][j] + dp[i-1][j-1]; S[i] == T[j]
// dp[i][j] depends on result of above and left, so if calculate from right to left,
// we can just use one dimension array
class Solution3
{
public:
    int numDistinct(string S, string T)
    {
        if (S.empty() || T.empty()) return 0;

        vector<int> dp(T.size() + 1); // T.size() + 1
        dp[0] = 1;
        for (int i = 0; i < S.size(); i++) {
            for (int j = T.size() - 1; j >= 0; j--) { // right to left
                dp[j + 1] += (T[j] == S[i] ? dp[j] : 0);
            }
        }

        return dp[T.size()];
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    Solution2 sol2;
    Solution3 sol3;

    string s("rabbbit"), t("rabbit");
    string s2("aabdbaabeeadcbbdedacbbeecbabebaeeecaeabaedadcbdbcdaabebdadbb"
              "aeabdadeaabbabbecebbebcaddaacccebeaeedababedeacdeaaaeeaecbe");
    string t2("bddabdcae");
    string s3("b"), t3("a");

    cout << sol.numDistinct(s, t) << endl;
    cout << sol.numDistinct(s2, t2) << endl;
    cout << sol.numDistinct(s3, t3) << endl;

    cout << sol2.numDistinct(s, t) << endl;
    cout << sol2.numDistinct(s2, t2) << endl;
    cout << sol2.numDistinct(s3, t3) << endl;

    cout << sol3.numDistinct(s, t) << endl;
    cout << sol3.numDistinct(s2, t2) << endl;
    cout << sol3.numDistinct(s3, t3) << endl;

    return 0;
}
