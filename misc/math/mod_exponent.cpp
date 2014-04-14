#include <iostream>

using namespace std;

// modulus and exponent
// a ^ b mod c
//
// (a*b)%c = ((a%c)*b)%c
// b = b0b1b2b3...b31 (binary)
// b = b0*2^31 + b1*2^30 + ... b31
// a^b = a^(b0*2^31) * a^(b1*2^30) * ... * a^(b31*2^0)
// so let ret = 1;
//    ret = (ret*ret)%c if bi = 0;
//    ret = (ret*a)%c if bi = 1
class Solution
{
public:
    int mod_exponent(int a, int b, int c)
    {
        int digit[32]; // store b's binary
        int i = 0, ret = 1;

        while (b) {
            digit[i++] = b & 0x1;
            b >>= 1;
        }

        for (int k = i - 1; k >= 0; k--) {
            ret = (ret * ret) % c;
            if (digit[k] == 1) {
                ret = (ret * a ) %c ;
            }
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    Solution sol;

    cout << sol.mod_exponent(3, 5, 4) << endl;

    return 0;
}
