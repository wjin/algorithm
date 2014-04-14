/*

   Pow(x, n)

   Implement pow(x, n).

*/

#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
    double do_positive_pow(double x, size_t n) // size_t
    {
        if (n == 0) return 1;
        else {
            double y = do_positive_pow(x, n >> 1); // shift
            y *= y;
            if ((n & 0x1) == 1) y *= x; // &
            return y;
        }
    }

public:
    double pow(double x, int n)
    {
        if (fabs(x - 0.0000001) <= 0) return 0; // judge double number
        if (n > 0) return do_positive_pow(x, n);
        else return 1 / do_positive_pow(x, -n);
    }
};

// iterative
class Solution2
{
// #define ISONE(n, i) (!!((n) & (1 << (i))))
    inline bool isone(int n, size_t i)
    {
        return (!!(n & (1 << i)));
    }

    double do_positive_pow(double x, size_t n) // size_t
    {
        int i = 31;
        while (i >= 0 && !isone(n, i)) i--; // find the most significant one bit

        double y = 1.0;
        while (i >= 0) {
            y *= y;
            if (isone(n, i)) y *= x;
            i--;
        }
        return y;
    }

public:
    double pow(double x, int n)
    {
        if (fabs(x - 0.0000001) <= 0) return 0; // judge double number
        if (n > 0) return do_positive_pow(x, n);
        else return 1 / do_positive_pow(x, -n);
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    Solution2 sol2;

    cout << sol.pow(2.1, 2) << endl;
    cout << sol.pow(2, -2) << endl;

    cout << sol2.pow(2.1, 2) << endl;
    cout << sol2.pow(2, -2) << endl;

    return 0;
}
