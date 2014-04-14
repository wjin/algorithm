#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{

public:
    void plusOne(vector<int> &digits)
    {
        if (digits.empty()) { // empty vector
            digits.push_back(1);
            return;
        }

        int n = digits.size() - 1;
        int carry = 0;
        bool firstTime = true;
        int sum = 0;

        do {
            sum = digits[n] + carry + (firstTime ? 1 : 0);
            digits[n] = sum >= 10 ? (sum - 10) : sum;
            carry = sum >= 10 ? 1 : 0;

            n--;
            firstTime = false;
        } while (carry && n >= 0);

        if (carry)
            digits.insert(digits.begin(), 1);
    }

    void print_one_to_n(size_t n)
    {
        vector<int> ret;
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
