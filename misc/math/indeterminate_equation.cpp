#include <iostream>

using namespace std;

// indeterminate equation
// calculate integer solution of equation: ax + by = c

// if ax + by = gcd(a, b) = g, has a solution (x0, y0),
// and c is a multiple of g, ax + by = c has a solution
// (x0, y0)
class Solution
{
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

public:
    bool indeterminate_equation(int a, int b, int c, int &x, int &y)
    {
        int gcd = egcd(a, b, x, y);

        if (c % gcd) return 0; // no solution

        int k = c / gcd;
        x = k * x;
        y = k * y;

        return 1;
    }
};

int main(int argc, char* argv[])
{
    Solution sol;
    int x = 0, y = 0;

    cout << sol.indeterminate_equation(9, 12, 7, x, y) << endl;
    cout << x << ' ' << y << endl;

    cout << sol.indeterminate_equation(9, 12, 24, x, y) << endl;
    cout << x << ' ' << y << endl;

    return 0;
}
