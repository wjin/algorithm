/*

 Merge Sorted Array

 Given two sorted integer arrays A and B, merge B into A as one sorted array.

 Note:
 You may assume that A has enough space to hold additional elements from B.
 The number of elements initialized in A and B are m and n respectively.

 */

#include <iostream>

using namespace std;

class Solution
{
public:
    void merge(int A[], int m, int B[], int n)
    {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (A[i] >= B[j])
                A[k--] = A[i--];
            else
                A[k--] = B[j--];
        }
        while (j >= 0) {
            A[k--] = B[j--];
        }
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    int a[6] = { 1, 3, 5 };
    int b[3] = { 2, 4, 6 };

    sol.merge(a, 3, b, 3);

    for (auto t : a)
        cout << t << ends;

    return 0;
}
