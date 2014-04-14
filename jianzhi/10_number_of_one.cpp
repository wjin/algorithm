#include <iostream>

using namespace std;

class Solution
{
public:
    int numberOfOne(int n)
    {
        int cnt = 0;
        while (n) {
            cnt++;
            n &= (n - 1);
        }
        return cnt;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    cout << sol.numberOfOne(1) << endl;
    cout << sol.numberOfOne(2) << endl;
    cout << sol.numberOfOne(3) << endl;
    cout << sol.numberOfOne(10) << endl;

    return 0;
}
