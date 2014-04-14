/*
 Single Number

 Given an array of integers, every element appears twice except for one.
 Find that single one.

 Note:
 Your algorithm should have a linear runtime complexity. Could you implement
 it without using extra memory?

 */

#include <iostream>

using namespace std;

class Solution
{
public:
    int singleNumber(int A[], int n)
    {
        int ret = 0;
        for (int i = 0; i < n; i++) {
            ret ^= A[i];
        }
        return ret;
    }
};

int main(int argc, char* argv[])
{
    int a[] = { 3, 3, 2 };
    Solution sol;

    cout << sol.singleNumber(a, sizeof(a) / sizeof(int)) << endl;

    return 0;
}
