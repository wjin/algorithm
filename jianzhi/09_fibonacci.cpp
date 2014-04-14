#include <iostream>

using namespace std;

class Solution
{
public:
    int fibonacci(int n)
    {
        int f1 = 0, f2 = 1;

        if (n == 1) return f1;
        if (n == 2) return f2;

        int i = 2;
        int tmp = 0;
        while (i < n) {
            tmp = f1 + f2;
            f1 = f2;
            f2 = tmp;
            i++;
        }

        return f2;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    cout << sol.fibonacci(1) << endl;
    cout << sol.fibonacci(2) << endl;
    cout << sol.fibonacci(3) << endl;
    cout << sol.fibonacci(4) << endl;
    cout << sol.fibonacci(5) << endl;

    return 0;
}
