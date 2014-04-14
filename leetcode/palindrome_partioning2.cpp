/*

 Palindrome Partitioning ||

 Given a string s, partition s such that every substring of the partition is a palindrome.

 Return the minimum cuts needed for a palindrome partitioning of s.

 For example, given s = "aab",
 Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.

 */

#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    // too slow and cannot pass OJ
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

    int minCut(string s)
    {
        int len = s.size();
        vector<int> dp(len, INT_MAX);

        dp[0] = 0;
        for (int i = 1; i < len; i++) {
            for (int j = i; j >= 0; j--) {
                if (isPalindrome(s, j, i)) {
                    if (j == 0)
                        dp[i] = 0;
                    else
                        dp[i] = min(dp[j - 1] + 1, dp[i]);
                }
            }
        }

        return dp[len - 1];
    }
};

// awesome: two DPs
class Solution2
{
public:
    void gen_palindrome_info(string &s, vector<vector<bool>> &isP)
    {
        // isP[i][j] is used to identify whether sub string of s(s[i]...s[j]) is palindrome
        // isP[i][j] == true only if: 1) s[i] == s[j] && 2) isP[i+1][j-1] == true
        // calculate column by column
        // start calculation from the second column
        for (int j = 1; j < s.size(); j++) {
            for (int i = 0; i <= j; i++) {
                if (s[i] == s[j]) {
                    if (j - i < 2)
                        isP[i][j] = true;
                    else {
                        isP[i][j] = isP[i + 1][j - 1];
                    }
                }
            }
        }
    }

    int minCut(string s)
    {
        int len = s.size();
        vector<int> dp(len, INT_MAX);
        vector<vector<bool>> isP(len, vector<bool>(len, 0));

        gen_palindrome_info(s, isP);
        dp[0] = 0;
        for (int i = 1; i < len; i++) {
            for (int j = i; j >= 0; j--) {
                if (isP[j][i]) {
                    if (j == 0)
                        dp[i] = 0;
                    else
                        dp[i] = min(dp[j - 1] + 1, dp[i]);
                }
            }
        }

        return dp[len - 1];
    }
};

int main(int argc, char* argv[])
{
    Solution sol;
    Solution2 sol2;
    string s("aab");

    cout << sol.minCut(s) << endl;
    cout << sol2.minCut(s) << endl;

    return 0;
}
