#include <iostream>

using namespace std;

// joseph problem
// total n numbers: 0 1...n-1, delete mth number eatch time
// f(n, m) = 0;                n=1
//         = (f(n-1,m) + m)%n; n>1
class Solution
{
public:
    int getLast(int n, int m)
    {
        if (n < 1 || m < 1) return -1;

        int last = 0;
        for (int i = 2; i <= n; i++) {
            last = (last + m) % i; // i
        }

        return last;
    }
};

int main(int argc, char* argv[])
{
    Solution sol;

    cout << sol.getLast(5, 3) << endl;

    return 0;
}
