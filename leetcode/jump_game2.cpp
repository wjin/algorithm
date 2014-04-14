/*

 Jump Game II

 Given an array of non-negative integers, you are initially positioned at the first index of the array.

 Each element in the array represents your maximum jump length at that position.

 Your goal is to reach the last index in the minimum number of jumps.

 For example:
 Given array A = [2,3,1,1,4]

 The minimum number of jumps to reach the last index is 2.
 (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

 */

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // cannot pass OJ large data test
    int jump(int A[], int n)
    {
        if (n <= 1)
            return 0;   // n == 1, 0 jump

        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] == INT_MAX)
                    continue; // cannot jump to i
                if (j + A[j] >= i) {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[n - 1] == INT_MAX ? 0 : dp[n - 1];
    }

    // cannot pass OJ large data test
    int jump2(int A[], int n)
    {
        if (n <= 1)
            return 0;   // n == 1, 0 jump

        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < n - 1; i++) {
            if (A[i] + i >= n - 1)
                return dp[i] + 1;
            for (int j = i + 1; j <= i + A[i]; j++) {
                dp[j] = min(dp[i] + 1, dp[j]);
            }
        }
        return dp[n - 1] == INT_MAX ? 0 : 1;
    }

    // can pass OJ large data test
    int jump3(int A[], int n)
    {
        if (n <= 1)
            return 0;   // n == 1, 0 jump

        int min_jumps = 0;
        int farest = 0;
        int start = 0, end = 0;

        while (start <= end) {
            ++min_jumps; // do one jump

            // calculate the farthest location
            for (int i = start; i <= end; i++)
                farest = max(farest, i + A[i]);

            if (farest >= n - 1)
                return min_jumps;
            /* no need as if farthest is not updated, start will greater than end
             else if (farthest == end) {
             return -1; // cannot jump
             } */

            // next jump
            start = end + 1;
            end = farest;
        }

        return -1;
    }
};

int main(int argc, char *argv[])
{
    int a1[] = { 2, 3, 1, 1, 4 };
    int a2[] = { 3, 2, 1, 0, 4 };
    int a3[] = { 0, 1 };
    int a4[] = { 1, 0, 1 };
    int a5[] = { 1, 2, 0, 1 };

    Solution sol;

    cout << sol.jump(a1, sizeof(a1) / sizeof(int)) << endl;
    cout << sol.jump(a2, sizeof(a2) / sizeof(int)) << endl;
    cout << sol.jump(a3, sizeof(a3) / sizeof(int)) << endl;
    cout << sol.jump(a4, sizeof(a4) / sizeof(int)) << endl;
    cout << sol.jump(a5, sizeof(a5) / sizeof(int)) << endl;

    cout << sol.jump2(a1, sizeof(a1) / sizeof(int)) << endl;
    cout << sol.jump2(a2, sizeof(a2) / sizeof(int)) << endl;
    cout << sol.jump2(a3, sizeof(a3) / sizeof(int)) << endl;
    cout << sol.jump2(a4, sizeof(a4) / sizeof(int)) << endl;
    cout << sol.jump2(a5, sizeof(a5) / sizeof(int)) << endl;

    cout << sol.jump3(a1, sizeof(a1) / sizeof(int)) << endl;
    cout << sol.jump3(a2, sizeof(a2) / sizeof(int)) << endl;
    cout << sol.jump3(a3, sizeof(a3) / sizeof(int)) << endl;
    cout << sol.jump3(a4, sizeof(a4) / sizeof(int)) << endl;
    cout << sol.jump3(a5, sizeof(a5) / sizeof(int)) << endl;

    return 0;
}
