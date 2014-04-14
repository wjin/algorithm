#include <iostream>

using namespace std;

// extention greatest common divisor
// gcd(a, b) = ax + by
//
// gcd(a, b) = ax1 + by1
// gcd(b, a % b) = bx2 + (a % b)y2 = bx2 + (a - (a/b)*b)y2
// gcd(a, b) = gcd(b, a%b) -> ax1 + by1= ay2 + (x2 - a/b * y2) * b
//
//
class Solution
{
public:
    // get coefficients x and y
    // x1 = y2
    // y1 = x2 - a / b * y2
    int egcd(int a, int b, int &x, int &y)
    {
        if (b == 0) {
            x = 1;
            y = 0;
            return a;
        } else {
            int gcd = egcd(b, a % b, x, y);
            int x2 = x, y2 = y;
            x = y2;
            y = x2 - (a / b) * y2;
            return gcd;
        }
    }

    int egcd_ite(int a, int b, int &x, int &y)
    {
        int x0, y0, x1, y1;

        x0 = 1;
        y0 = 0;
        x1 = 0;
        y1 = 1;
        x = 0;
        y = 1;

        int r = a % b; // remainder
        int q = a / b; // quotient

        while (r) {
            x = x0 - q * x1;
            y = y0 - q * y1;

            x0 = x1;
            y0 = y1;
            x1 = x;
            y1 = y;

            a = b;
            b = r;
            r = a % b;
            q = a / b;
        }

        return b; // b
    }
};

int main(int argc, char* argv[])
{
    Solution sol;
    int x = 0, y = 0;

    cout << sol.egcd(9, 12, x, y) << endl;
    cout << x << ' ' << y << endl;

    cout << sol.egcd_ite(9, 12, x, y) << endl;
    cout << x << ' ' << y << endl;

    cout << sol.egcd(12, 9, x, y) << endl;
    cout << x << ' ' << y << endl;

    cout << sol.egcd_ite(12, 9, x, y) << endl;
    cout << x << ' ' << y << endl;

    return 0;
}
