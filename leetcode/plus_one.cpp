#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        if (digits.empty()) { // empty vector
            digits.push_back(1);
            return digits;
        }

        int n = digits.size() - 1;
        int addition = 1;
        int carry = 0;
        int sum = 0;

        do {
            sum = digits[n] + carry + addition;
            digits[n] = sum >= 10 ? (sum - 10) : sum;
            carry = sum >= 10 ? 1 : 0;

            n--;
            addition = 0;
        } while (carry && n >= 0);

        if (carry)
            digits.insert(digits.begin(), 1);

        return digits;
    }
};

void print_ret(vector<int> &ret)
{
    for (auto e : ret)
        cout << e << ' ';
    cout << endl;
}

int main(int argc, char *argv[])
{
    Solution sol;

    vector<int> v1;
    vector<int> v2 = { 1, 1 };
    vector<int> v3 = { 1, 9, 9 };
    vector<int> v4 = { 9, 9, 9 };

    vector<int> ret = sol.plusOne(v1);
    print_ret(ret);

    ret = sol.plusOne(v2);
    print_ret(ret);

    ret = sol.plusOne(v3);
    print_ret(ret);

    ret = sol.plusOne(v4);
    print_ret(ret);
}

