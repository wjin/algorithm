#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isOdd(int n)
{
    return n & 0x1;
}

bool divide3(int n)
{
    return n % 3 == 0;
}

class Solution
{
public:
    void partition(vector<int> &v, bool (*func)(int))
    {
        int len = v.size();
        if (len <= 1) return;

        int low = 0, high = len -1;

        while (low < high) {
            if (func(v[low])) low++;
            else if (!func(v[high])) high--;
            else {
                swap(v[low], v[high]);
            }
        }
    }
};

void print_vec(vector<int> &v)
{
    for (auto e : v)
        cout << e << endl;
}

int main(int argc, char *argv[])
{
    Solution sol;

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    sol.partition(v, isOdd);
    print_vec(v);

    sol.partition(v, divide3);
    print_vec(v);

    return 0;
}
