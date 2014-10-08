#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{

public:
    void plusOne(vector<int> &digits)
    {
        int n = digits.size() - 1;
        int carry = 1;
        int sum = 0;

        while (carry && n >= 0) {
            sum = digits[n] + carry;
            digits[n] = sum % 10;
            carry = sum / 10;
            n--;
        }

        if (carry)
            digits.insert(digits.begin(), 1);
    }

    void print_one_to_n(size_t n)
    {
        vector<int> ret(1, 0);
        while (true) {
            plusOne(ret);
            if (ret.size() == n + 1) break;

            for_each(ret.begin(), ret.end(), [](int n) {
                cout << n;
            });
            cout << endl;
        }
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    sol.print_one_to_n(1);
    sol.print_one_to_n(2);

    return 0;
}
