#include <iostream>
#include <string>

using namespace std;

// modulus of big integer
// a mod b; 1 ¡Ü a ¡Ü 10^1000, 1 ¡Ü b ¡Ü 100000
class Solution
{
public:
    int mod(string s, int n)
    {
        int mod  = 0;
        for (size_t i = 0; i < s.size(); i++) {
#if 0
            mod *= 10;
            mod += s[i] - '0';
            mod %= n;
#endif
            mod = (mod * 10 + s[i] - '0') % n;
        }
        return mod;
    }
};

int main(int argc, char* argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    // freopen("output","w",stdout);
#endif

    Solution sol;
    string s;
    int n;

    while (cin >> s >> n) {
        cout << sol.mod(s, n) << endl;
    }

    return 0;
}
