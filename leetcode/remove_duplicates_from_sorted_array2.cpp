/*

 Remove Duplicates from Sorted Array ||

 Follow up for "Remove Duplicates":
 What if duplicates are allowed at most twice?

 For example,
 Given sorted array A = [1,1,1,2,2,3],

 Your function should return length = 5, and A is now [1,1,2,2,3].

 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(int A[], int n)
    {
        if (n <= 1) // n = 0 or 1
            return n;

        int i = 0, j = 1;
        while (j < n) {
            if (A[j] == A[i]) {
                A[++i] = A[j++]; // copy first duplicate element
                while (A[j] == A[i])
                    j++; // skip following duplicate elements
            } else {
                A[++i] = A[j++];
            }
        }

        return i + 1;
    }

    int removeDuplicates2(int A[], int n)
    {
        if (n <= 2) // n = 0 or 1
            return n;

        int i = 2, j = 2;
        for (; j < n; j++)
            if (A[i - 2] != A[j]) {
                A[i++] = A[j];
            }
        return i;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    int a[6] = { 1, 1, 1, 2, 2, 3 };

    cout << sol.removeDuplicates(a, 6) << endl;

    for (auto t : a)
        cout << t << ends;

    return 0;
}
