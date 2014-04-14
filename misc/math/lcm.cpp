#include <iostream>

using namespace std;

// least common multiple
// lcm(a, b) = a * b / gcd(a, b)
class Solution
{
private:
    int gcd_rec(int a, int b)
    {
        if (b == 0) return a;
        return gcd_rec(b, a % b);
    }
public:
    int lcm(int a, int b)
    {
        return a * b / gcd_rec(a, b);
    }
};

int main(int argc, char* argv[])
{
    Solution sol;

    cout << sol.lcm(12, 9) << endl;

    return 0;
}
