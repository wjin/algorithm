/*

5.1

You are given two 32-bit numbers, N and M, and two bit positions, i and j.
Write a method to set all bits between i and j in N equal to M (e.g., M
becomes a substring of N located at i and starting at j).

EXAMPLE:

Input: N = 10000000000, M = 10101, i = 2, j = 6

Output: N = 10001010100

*/

#include <iostream>
#include <bitset>

using namespace std;

class Solution
{
public:
    int setBit(int n, int m, int i, int j)
    {
        bitset<32> bitn(n);
        bitset<32> bitm(m);

        for (int nk = i, mk = 0; nk <= j; nk++) {
            bitn[nk] = bitm[mk++];
        }

        return bitn.to_ulong();
    }
};

class Solution2
{
public:
    int setBit(int n, int m, int i, int j)
    {
        int lMask = n & (~((1 << (j + 1)) - 1));
        int rMask = n & ((1 << i) - 1);
        int mask = lMask | rMask;

        return mask | (m << i);
    }
};

int main()
{
    int n = 1024;//10000000000
    int m = 21; //10101
    int i = 2;
    int j = 6;

    Solution sol;
    cout << bitset<32>(sol.setBit(n, m, i, j)) << endl;

    Solution2 sol2;
    cout << bitset<32>(sol2.setBit(n, m, i, j)) << endl;

    return 0;
}
