/*

 Jump Game

 Given an array of non-negative integers, you are initially positioned at the first index of the array.

 Each element in the array represents your maximum jump length at that position.

 Determine if you are able to reach the last index.

 For example:
 A = [2,3,1,1,4], return true.

 A = [3,2,1,0,4], return false.

 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // dp
    bool canJump(int A[], int n)
    {
        if (n <= 0)
            return false;

        vector<bool> dp(n);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] && (j + A[j]) >= i) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n - 1];
    }

    // backward
    bool canJump2(int A[], int n)
    {
        int cur = n - 1;
        for (int i = cur - 1; i >= 0; i--) {
            if (A[i] + i >= cur)
                cur = i;
        }

        return cur == 0;
    }

    // forward
    bool canJump3(int A[], int n)
    {
        int farest = 0;
        int i = 0;
        for (i = 0; i < n; i++) {
            if (i <= farest) { // can jump
                farest = max(A[i] + i, farest);
            } else
                break; // cannot jump
        }

        return i == n || farest >= n;
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

    cout << sol.canJump(a1, sizeof(a1) / sizeof(int)) << endl;
    cout << sol.canJump(a2, sizeof(a2) / sizeof(int)) << endl;
    cout << sol.canJump(a3, sizeof(a3) / sizeof(int)) << endl;
    cout << sol.canJump(a4, sizeof(a4) / sizeof(int)) << endl;
    cout << sol.canJump(a5, sizeof(a5) / sizeof(int)) << endl;

    cout << sol.canJump2(a1, sizeof(a1) / sizeof(int)) << endl;
    cout << sol.canJump2(a2, sizeof(a2) / sizeof(int)) << endl;
    cout << sol.canJump2(a3, sizeof(a3) / sizeof(int)) << endl;
    cout << sol.canJump2(a4, sizeof(a4) / sizeof(int)) << endl;
    cout << sol.canJump2(a5, sizeof(a5) / sizeof(int)) << endl;

    cout << sol.canJump3(a1, sizeof(a1) / sizeof(int)) << endl;
    cout << sol.canJump3(a2, sizeof(a2) / sizeof(int)) << endl;
    cout << sol.canJump3(a3, sizeof(a3) / sizeof(int)) << endl;
    cout << sol.canJump3(a4, sizeof(a4) / sizeof(int)) << endl;
    cout << sol.canJump3(a5, sizeof(a5) / sizeof(int)) << endl;

    return 0;

}
