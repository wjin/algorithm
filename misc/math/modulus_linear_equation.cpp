#include <iostream>

using namespace std;

// modulus of linear equation
// ax = b mod n (means ax % n = b % n)
//

// analysis:
// if gcd(a, n)|b, ax=b%n has gcd(a,n) answers
// the problem is equal to calculate: ax + ny = b
// let d=gcd(a, n) and a*x0 + n*y0 = d
// a*x0*(b/d) + n*y0*(b/d) = b
// so one solution is: x=x0*(b/d), y=y0*(b/d)
//
//
// modulus' inverse:
// gcd(a,n)=1
// ax=b mod n has one solution
// and can calculate it from: ax + ny = 1
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
    bool modulus_linear_equation(int a, int b, int n, int &x, int &y)
    {
        int gcd = egcd(a, n, x, y);

        if (b % gcd) return 0; // no solution

        int x0 = x * (b / gcd) % n; // specific solution

        for (int i = 0; i < gcd; i++)
            cout << ((x0 + i * (n / gcd)) % n) << endl; // print solution

        return 1;
    }
};

int main(int argc, char* argv[])
{
    Solution sol;
    int x = 0, y = 0;

    cout << sol.modulus_linear_equation(5, 4, 3, x, y) << endl;
    cout << x << ' ' << y << endl;

    return 0;
}
