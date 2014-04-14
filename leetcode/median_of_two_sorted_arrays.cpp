/*

 Median of Two Sorted Arrays

 There are two sorted arrays A and B of size m and n respectively.
 Find the median of the two sorted arrays. The overall run time
 complexity should be O(log (m+n)).

 */


/*
  more info: http://www.geeksforgeeks.org/median-of-two-sorted-arrays/
  (two arrays have the same size)

 */

#include <iostream>

using namespace std;

class Solution
{
public:
    // a[] has m numbers from 0...m-1
    // b[] has n numbers from 0...n-1
    double findKth(int a[], int m, int b[], int n, int k)
    {
        if (m > n) // keep m is little than or equal to n
            return findKth(b, n, a, m, k);

        // simple case to get the kth number
        if (m == 0)
            return b[k - 1];
        if (k == 1)
            return min(a[0], b[0]);

        // partition k numbers to two arrays
        // the small array has at most k/2 numbers
        int pa = min(k / 2, m);
        int pb = k - pa;

        if (a[pa - 1] < b[pb - 1]) { // kth number is located in either a[pa...m-1] or b[0...n-1]
            return findKth(a + pa, m - pa, b, n, k - pa);
        } else if (a[pa - 1] > b[pb - 1]) { // kth number is located in either a[0...m-1] to b[pb...n-1]
            return findKth(a, m, b + pb, n - pb, k - pb);
        } else {
            return a[pa - 1];
        }
    }

    double findMedianSortedArrays(int A[], int m, int B[], int n)
    {
        if (m == 0 && n == 0) { // invalid
            return -1;
        }

        long long total = m + n; // m + n may overflow
        if (total % 2 == 1) { // odd
            return findKth(A, m, B, n, total / 2 + 1);
        } else { // even, get middle two numbers and calculate average
            return (findKth(A, m, B, n, total / 2)
                    + findKth(A, m, B, n, total / 2 + 1)) / 2;
        }
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    int a[] = { 1, 2 };
    int b[] = { 1, 2, 3 };

    double ret = sol.findMedianSortedArrays(a, sizeof(a) / sizeof(int), b,
                                            sizeof(b) / sizeof(int));
    cout << showpoint << ret << endl;

    // bug
    ret = sol.findMedianSortedArrays(a, 0, b, sizeof(b) / sizeof(int));
    cout << ret << endl;

    // bug
    int b2[] = { 2, 3 };
    ret = sol.findMedianSortedArrays(a, 0, b2, sizeof(b2) / sizeof(int));
    cout << ret << endl;

    return 0;
}
