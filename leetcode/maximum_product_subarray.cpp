/*

Maximum Product Subarray

Find the contiguous subarray within an array (containing at least one
number) which has the largest product.

For example, given the array [2,3,-2,4], the contiguous
subarray [2,3] has the largest product = 6.

*/

#include <iostream>

using namespace std;

class Solution
{
public:
    // keep two values: minHere and maxHere ending with each index i
    int maxProduct(int A[], int n)
    {
        if (n < 1) return 0;

        int ret, minHere, maxHere, t;

        ret = minHere = maxHere = A[0];
        for (int i = 1; i < n; i++) {
            t = minHere;
            minHere = min({ A[i], minHere * A[i], maxHere * A[i] });
            maxHere = max({ A[i], t * A[i], maxHere * A[i] });
            ret = max(ret, maxHere);
        }

        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    int a[] = { 2, 3, -2, 4 };

    cout << sol.maxProduct(a, sizeof(a) / sizeof(a[0])) << endl;

    return 0;
}
