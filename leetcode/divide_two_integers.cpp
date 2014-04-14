/*

 Divide Two Integers

 Divide two integers without using multiplication, division and mod operator

 */

#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        // invalid input
        if (divisor == 0)
            return -1;

        // simple input
        if (divisor == 1)
            return dividend;
        if (divisor == -1)
            return -dividend;

        // deal with sign
        int sign = 1;
        if (dividend < 0)
            sign = -sign;
        if (divisor < 0)
            sign = -sign;

        // convert dividend and divisor to long long to avoid overflow
        // and get their absolute value
        long long dend = abs((long long) dividend);
        long long dsor = abs((long long) divisor);

        int curNum = 1;
        while (dend > dsor) {
            dsor <<= 1;
            curNum <<= 1;
        }

        int ret = 0;
        while (dend >= abs((long long) divisor)) { // =, long long
            // calculate curNum
            while (dend >= dsor) { // =
                dend -= dsor;
                ret += curNum;
            }

            // decrease divisor
            dsor >>= 1;
            curNum >>= 1;
        }

        return sign * ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    cout << sol.divide(12, 0) << endl;
    cout << sol.divide(12, 1) << endl;
    cout << sol.divide(12, -1) << endl;
    cout << sol.divide(12, 2) << endl;
    cout << sol.divide(12, -2) << endl;

    return 0;
}
