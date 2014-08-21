/*

5.2

Given a real number between 0 and 1 (e.g., 0.72) that is passed in as a double,
print the binary representation. If the number cannot be represented accurately
in binary with at most 32 characters, print "ERROR."

*/

#include <iostream>
#include <cmath>

using namespace std;

class Solution
{
public:
    string doubleToBinary(double d)
    {
        string ret(".");
        const int maxBit = 32;

        while (d > 0) { // compare with precision ?
            if (ret.size() >= maxBit) return "ERROR";

            d *= 2;
            if (d >= 1) { //
                ret += '1';
                d = d - 1;
            } else {
                ret += '0';
            }
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    double n = 0.72;
    double n2 = 0.75;

    cout << sol.doubleToBinary(n) << endl;
    cout << sol.doubleToBinary(n2) << endl;

    return 0;
}
