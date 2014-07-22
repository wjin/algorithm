/*

 Plus One

 Given a non-negative number represented as an array of digits, plus one to the number.

 The digits are stored such that the most significant digit is at the head of the list.

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size() - 1;
        int carry = 1;
        int sum = 0;

        while (n >= 0 && carry) {
            sum = digits[n] + carry;
            digits[n] = sum % 10;
            carry = sum / 10;
            n--;
            // digits[n] = sum >= 10 ? (sum - 10) : sum;
            // carry = sum >= 10 ? 1 : 0;
        }

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

