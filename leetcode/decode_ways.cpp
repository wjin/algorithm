/*

 Decode Ways

 A message containing letters from A-Z is being encoded to numbers using the following mapping:

 'A' -> 1
 'B' -> 2
 ...

 'Z' -> 26

 Given an encoded message containing digits, determine the total number of ways to decode it.

 For example,
 Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

 The number of ways decoding "12" is 2.

 */

// Note:  be careful with '0'
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int numDecodings(string s)
    {
        int len = s.size();
        if (len == 0 || s[0] == '0') // leading with '0' is invalid
            return 0;

        vector<int> dp(len + 1, 0);
        dp[0] = 1; //
        dp[1] = 1;
        for (int i = 2; i <= len; i++) {
            char prev = s[i - 2], cur = s[i - 1];

            // s[i-1] is alone
            if (cur != '0') {  // be careful
                dp[i] += dp[i - 1];
            }

            // s[i-2] and s[i-1] decode together
            if (prev == '1' || (prev == '2' && cur <= '6')) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[len];
    }
};

int main(int argc, char *argv[])
{
    string s1("12");
    string s2("121");
    string s3("0");
    string s4("1210");

    Solution sol;

    cout << sol.numDecodings(s1) << endl;
    cout << sol.numDecodings(s2) << endl;
    cout << sol.numDecodings(s3) << endl;
    cout << sol.numDecodings(s4) << endl;

    return 0;
}
