/*
 Reverse Integer

 Reverse digits of an integer.

 Example1: x = 123, return 321
 Example2: x = -123, return -321

 click to show spoilers.

 Have you thought about this?
 Here are some good questions to ask before coding.
 Bonus points for you if you have already thought through this!

 If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

 Did you notice that the reversed integer might overflow?
 Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows.
 How should you handle such cases?

 Throw an exception? Good, but what if throwing an exception is not an option?
 You would then have to re-design the function (ie, add an extra parameter).

 */

#include <iostream>
#include <climits>

using namespace std;

class Solution
{
private:
    bool invalid;
public:
    Solution() :
        invalid(false)
    {
    }

    int reverse(int x)
    {
        invalid = false;
        bool minus = false;
        long long ret = 0;
        long long t = x;

        if (t < 0) {
            minus = true;
            t = -t;
        }

        while (t) {
            ret = ret * 10 + t % 10;
            t /= 10;
        }

        if (ret > INT_MAX) {
            invalid = true;
            return 0;
        } else {
            return minus ? -ret : ret;
        }
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    cout << sol.reverse(0) << endl;
    cout << sol.reverse(123) << endl;
    cout << sol.reverse(-123) << endl;
    cout << sol.reverse(12300) << endl;
    cout << sol.reverse(-12300) << endl;
    cout << sol.reverse(9999999LL) << endl;

    return 0;
}
