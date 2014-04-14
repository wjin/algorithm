/*

 First Missing Positive

 Given an unsorted integer array, find the first missing positive integer.

 For example,
 Given [1,2,0] return 3,
 and [3,4,-1,1] return 2.

 Your algorithm should run in O(n) time and uses constant space.

 */

#include <iostream>

using namespace std;

class Solution
{
public:
    int firstMissingPositive(int A[], int n)
    {
        // swap A[i] to the appropriate position in the array if sorted
        // ignore zero and negative numbers
        for (int i = 0; i < n; i++) {
            // A[i] != i + 1 means A[i] is not in the right position
            // as array start from 0, so A[0] = 1

            // A[i] != A[A[i] - 1], this is for duplicate numbers
            // if it is in the right place, exit while

            while (A[i] > 0 && A[i] <= n && A[i] != i + 1 && A[i] != A[A[i] - 1]) {
                swap(A[i], A[A[i] - 1]);
            }
        }

        // find the first miss match: A[i] != i + 1
        int i;
        for (i = 0; i < n; i++) {
            if (A[i] != i + 1)
                break;
        }
        return i + 1;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    int a1[] = { 1, 2, 0 };
    int a2[] = { 3, 4, -1, 1 };
    int a3[] = { 1, 1 }; // bug, duplicate numbers

    cout << sol.firstMissingPositive(a1, sizeof(a1) / sizeof(int)) << endl;
    cout << sol.firstMissingPositive(a2, sizeof(a2) / sizeof(int)) << endl;
    cout << sol.firstMissingPositive(a3, sizeof(a3) / sizeof(int)) << endl;

    return 0;

}
