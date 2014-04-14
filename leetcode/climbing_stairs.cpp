/*

 Climbing Stairs

 You are climbing a staircase. It takes n steps to reach to the top.
 Each time you can either climb 1 or 2 steps. In how many distinct ways
 can you climb to the top?

 */

#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1; // bug
        int s1 = 1, s2 = 2;
        for (int i = 3; i <= n; i++) {
            int t = s1 + s2;
            s1 = s2;
            s2 = t;
        }

        return s2;
    }

    int climbStairs2(int n)
    {
        if (n == 1)
            return 1;

        double root5 = sqrt(5);
        return (1 / root5) * (pow((1 + root5) / 2, n + 1) - pow((1 - root5) / 2, n + 1)); // n + 1
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    for (int i = 1; i <= 10; i++) {
        cout << sol.climbStairs(i) << endl;
        cout << sol.climbStairs2(i) << endl;
    }

    return 0;
}
