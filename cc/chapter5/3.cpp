/*

5.3

Given a positive integer, print the next smallest and the previous largest number
that have the same number of 1 bits in their binary representation.

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int nextSmallest(int num)
    {
        if (num <= 0) return -1;

        int n = num, cnt0 = 0, cnt1 = 0;

        // count number of tailing zeros
        while ((n & 0x1) == 0) {
            cnt0++;
            n >>= 1;
        }

        // number of 1 before a non-tailing 0
        while ((n & 0x1) == 1) {
            cnt1++;
            n >>= 1;
        }

        int idx = cnt0 + cnt1; // position of non-tailing 0

        // error handling, such as: 11...1100...00
        if (idx == 31) return -1;

        num |= (1 << idx); // set bit: idx
        num &= ~((1 << idx) - 1); // clear bits: [0...idx)
        num |= ((1 << (cnt1 - 1)) - 1); // set bits: [0...cnt1-1)

        return num;
    }

    int preLargest(int num)
    {
        if (num <= 0) return -1;

        int n = num, cnt0 = 0, cnt1 = 0;

        // count number of tailing ones
        while ((n & 0x1) == 1) {
            cnt1++;
            n >>= 1;
        }

        // error handling, such as: 00...0011...11
        if (n == 0) return -1;

        // number of 0 before a non-tailing 1
        while ((n & 0x1) == 0) {
            cnt0++;
            n >>= 1;
        }

        int idx = cnt0 + cnt1; // position of non-tailing 0

        // num &= ~((1 << (idx + 1)) - 1); // clear bits: [0...idx]
        num &= (~0) << (idx + 1); // clear bits: [0...idx]

        //int mask = (1 << idx) - 1;
        //mask &= ~((1 << cnt0 - 1) - 1);
        int mask = (1 << (cnt1 + 1)) - 1; // cnt1 + 1
        mask <<= (cnt0 - 1);

        num |= mask; // set bits: [cnt1-1...idx]

        return num;
    }
};

void test(int n)
{
    Solution sol;

    int next = sol.nextSmallest(n);
    int pre = sol.preLargest(n);

    cout << bitset<32>(n) << ' ' << n << endl;
    cout << bitset<32>(next) << ' ' << next << endl;
    cout << bitset<32>(pre) << ' ' << pre << endl;
}

int main()
{
    vector<int> v = { 1000, 2, 3, INT_MAX, INT_MIN };

    for (auto e : v)
        test(e);

    return 0;
}
