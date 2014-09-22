/*

 Divide Two Integers

 Divide two integers without using multiplication, division and mod operator

 */

#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
private:
    int divide_positive(unsigned long long dd, unsigned long long dv)
    {
        unsigned long long tdv = dv;
        unsigned long long base = 1; // long long

        while (dd > tdv) {
            tdv <<= 1;
            base <<= 1;
        }

        int ret = 0;
        while (dd >= dv) { // =
            while (dd >= tdv) { // =
                dd -= tdv;
                ret += base;
            }

            // decrease dv and base
            tdv >>= 1;
            base >>= 1;
        }
        return ret;
    }

    int divide_positive2(unsigned long long dd, unsigned long long dv)
    {
        int ret = 0;
        while (dd >= dv) { // =
            unsigned long long tdv = dv;

            for (int i = 0; dd >= tdv; i++, tdv <<= 1) {
                dd -= tdv;
                ret += (1 << i);
            }
        }

        return ret;
    }

public:
    int divide(int dividend, int divisor)
    {
        // invalid input
        if (divisor == 0) throw runtime_error("divide by zero");

        // simple input
        if (dividend == 0) return 0;

        // deal with sign
        bool minus = ((dividend ^ divisor) >> 31) ? 1 : 0;

        // convert dividend and divisor to long long to avoid
        // overflow and get their absolute value
        unsigned long long dd = llabs(dividend);
        unsigned long long dv = llabs(divisor);

        int ret = divide_positive(dd, dv);
        return minus ? -ret : ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    // cout << sol.divide(12, 0) << endl;
    cout << sol.divide(12, 1) << endl;
    cout << sol.divide(12, -1) << endl;
    cout << sol.divide(12, 2) << endl;
    cout << sol.divide(12, -2) << endl;
    cout << sol.divide(2147483647, 1) << endl;

    return 0;
}
