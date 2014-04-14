/*

   Sqrt(x)

   Implement int sqrt(int x).

   Compute and return the square root of x.

*/

#include <iostream>
#include <climits>

using namespace std;

/*

 mathematic solution refer:
      http://oj.leetcode.com/discuss/1015/any-folks-passed-this-problem-without-using-math-sqrt
*/

// simple solution
class Solution
{
public:
    int sqrt(int x)
    {
        if (x < 0) return -1; // invalid
        if (x < 2) return x;

        int maxRoot = 1 << 16; // upper bound for sqrt(x)
        while (maxRoot > x) maxRoot >>= 1; // decrease uppder bound according to x

        int low = 1, high = maxRoot;
        int mid = 0;
        int prev_mid = 0; // need to preserve previous mid as mid * mid will never equal to x in some cases
        while (low <= high) {
            mid = low + (high - low) / 2;
            if ( x / mid > mid) { // mid * mid will overflow as x is int , not unsigned int
                low = mid + 1;;
                prev_mid = mid;
            } else if (x / mid < mid) {
                high = mid -1;
            } else {
                return mid;
            }
        }
        return prev_mid;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    cout << sol.sqrt(1) << endl;
    cout << sol.sqrt(2) << endl;
    cout << sol.sqrt(3) << endl;
    cout << sol.sqrt(9) << endl;
    cout << sol.sqrt(12) << endl;
    cout << sol.sqrt(16) << endl;
    cout << sol.sqrt(99) << endl;
    cout << sol.sqrt(100) << endl;
    cout << sol.sqrt(2147395599) << endl; // bug
    return 0;
}
