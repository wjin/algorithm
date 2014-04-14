/*
 Single Number ||

 Given an array of integers, every element appears three times
 except for one. Find that single one.

 Note:
 Your algorithm should have a linear runtime complexity.
 Could you implement it without using extra memory?

 */

#include <iostream>

using namespace std;

class Solution
{
public:
    // using two bits to record the XOR status (00, 01, 10, 11)
    // (highBit, lowBit)
    // lowBit == 1 means single element
    // highBit == 1 means two elements XOR
    // lobBit == 1 && highBit == 1 means three elements XOR
    // 1) if lowBit == 1 and another 1 is coming, we need to set highBit to 1
    // 2) if both lowBit and highBit are 1, we need to reset them to 0 using mask
    // lowBit stands for one single element while highBit stands for two elements.
    int singleNumber(int A[], int n)
    {
        int lowBit = 0, highBit = 0, mask = 0;
        for (int i = 0; i < n; i++) {
            highBit |= (lowBit & A[i]);
            lowBit ^= A[i];
            mask = ~(lowBit & highBit);
            lowBit &= mask;
            highBit &= mask;
        }
        return lowBit;
    }

    // accumulate each bit and mod 3
    int singleNumber2(int A[], int n)
    {
        int ret = 0;
        int curBit = 0;
        for (int i = 0; i < 32; i++) {
            curBit = 0;
            for (int j = 0; j < n; j++)
                if ((A[j] >> i) & 1) {
                    curBit = (curBit + 1) % 3;
                }
            ret |= (curBit << i);
        }

        return ret;
    }
};

int main(int argc, char* argv[])
{
    int a[] = { 3, 3, 3, 2 };
    Solution sol;

    cout << sol.singleNumber(a, sizeof(a) / sizeof(int)) << endl;
    cout << sol.singleNumber2(a, sizeof(a) / sizeof(int)) << endl;

    return 0;
}
