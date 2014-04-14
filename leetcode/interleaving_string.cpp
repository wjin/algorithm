/*

   Interleaving String

   Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

   For example,
   Given:
     s1 = "aabcc",
     s2 = "dbbca",

   When s3 = "aadbbcbcac", return true.
   When s3 = "aadbbbaccc", return false.

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        size_t len1 = s1.size(), len2 = s2.size(), len3 = s3.size();
        if (len1 + len2 != len3) return false;

        // dp[i][j] == true means s1(0...i-1) and s2(0...j-1) interleave s3(0...i+j-1)
        // dp[len1][len2] is the result
        vector<vector<bool>> dp(len1 + 1, vector<bool>(len2 + 1, true));

        for (size_t i = 1 ; i <= len1; i++) {
            dp[i][0] = dp[i - 1][0] && s1[i - 1] == s3[i - 1];
        }

        for (size_t j = 1 ; j <= len2; j++) {
            dp[0][j] = dp[0][j - 1] && s2[j - 1] == s3[j - 1];
        }

        for (size_t i = 1 ; i <= len1; i++) {
            for (size_t j = 1 ; j <= len2; j++) {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                           (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }

        return dp[len1][len2];
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    string s1("aabcc");
    string s2("dbbca");

    string s3("aadbbcbcac");
    string s4("aadbbbaccc");

    cout << sol.isInterleave(s1, s2, s3) << endl;
    cout << sol.isInterleave(s1, s2, s4) << endl;

    return 0;
}
