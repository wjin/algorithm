#include <iostream>

using namespace std;

// sqrt
// using newton iteration algorithm
// Xk+1 = (Xk + n/Xk) / 2
class Solution
{
private:
    const int times;
public:
    Solution(const int n = 1000) : times(n) {}
    double getSqrt(int n)
    {
        // sqrt(1) = 1
        double x = 1; // initial value, we set it to other similar value

        for (int i = 0; i < times; i++) {
            x = (x + n / x) / 2;
        }

        return x;
    }
};

int main(int argc, char* argv[])
{
    Solution sol;

    cout << sol.getSqrt(2) << endl;
    cout << sol.getSqrt(3) << endl;
    cout << sol.getSqrt(4) << endl;
    cout << sol.getSqrt(5) << endl;

    return 0;
}
