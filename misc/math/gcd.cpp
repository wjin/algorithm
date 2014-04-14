#include <iostream>

using namespace std;

// greatest common divisor
// Euclidean algorithm
class Solution
{
public:
    // gcd(a, b) = gcd(b, a mod b)

	// Proof:
	// (A) let d = gcd(a, b)
	// a = kb + r -> r = a mod b, a - kb = r (1)
	// d is gcd -> d|a, d|b   (2)
	// (1), (2) -> d|r -> d=gcd(b, r)
	//
	// (B) let d = gcd(b, a mod b)
	//  r = a mod b -> d|b, d|r
	//  a = kb + r -> d|a -> d=gcd(a, b)

	// gcd(a, b) and gcd(b, a mod b) have the same common divisor
	// so does the greatest common divisor
    int gcd_rec(int a, int b)
    {
        if (b == 0) return a;
        return gcd_rec(b, a % b);
    }

    int gcd_ite(int a, int b)
    {
        int mod = 0;
        while (b) {
            mod = a % b;
            a = b;
            b = mod;
        }

        return a;
    }

    int gcd_ite2(int a, int b)
    {
        while (a != b) {
            if (a > b) a -= b;
            else b -= a;
        }
        return a;
    }
};

int main(int argc, char* argv[])
{
    Solution sol;

    cout << sol.gcd_rec(9, 12) << endl;
    cout << sol.gcd_rec(12, 9) << endl;

    cout << sol.gcd_ite(9, 12) << endl;
    cout << sol.gcd_ite(12, 9) << endl;

    cout << sol.gcd_ite2(9, 12) << endl;
    cout << sol.gcd_ite2(12, 9) << endl;

    return 0;
}
