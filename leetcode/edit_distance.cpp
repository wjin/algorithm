/*

 Edit Distance

 Given two words word1 and word2, find the minimum number of steps
 required to convert word1 to word2. (each operation is counted as 1 step.)

 You have the following 3 operations permitted on a word:

 a) Insert a character
 b) Delete a character
 c) Replace a character

 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        int row = word1.size(), col = word2.size();
        vector<vector<int> > dp(row + 1, vector<int>(col + 1, 0));

        for (int i = 0; i <= row; i++)
            dp[i][0] = i;
        for (int j = 0; j <= col; j++)
            dp[0][j] = j;

        for (int i = 1; i <= row; i++) {
            for (int j = 1; j <= col; j++)
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else {
                    dp[i][j] = min(
                    { dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1] })
                    + 1;
                }
        }

        return dp[row][col];
    }
};

int main(int argc, char *argv[])
{
    string s1("abc"), s2("a");
    Solution sol;

    cout << sol.minDistance(s1, s2) << endl;

    return 0;
}
