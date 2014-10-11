#include <iostream>

using namespace std;

class Solution
{
public:
    int addTwoNum(int n1, int n2)
    {
        if (n2 == 0) return n1;
        return addTwoNum(n1 ^ n2, (n1 & n2) << 1);
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    cout << sol.addTwoNum(1, 2) << endl;
    cout << sol.addTwoNum(5, 6) << endl;
    cout << sol.addTwoNum(23, 80) << endl;

    return 0;
}
