/*

 Remove Duplicates from Sorted Array

 Given a sorted array, remove the duplicates in place such that
 each element appear only once and return the new length.

 Do not allocate extra space for another array, you must do this in place
 with constant memory.

 For example,
 Given input array A = [1,1,2],

 Your function should return length = 2, and A is now [1,2].

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
            if (A[j] == A[i])
                j++;
            else {
                A[++i] = A[j++];
            }
        }

        return i + 1;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    int a[3] = { 1, 1, 2 };

    cout << sol.removeDuplicates(a, 3) << endl;

    for (auto t : a)
        cout << t << ends;

    return 0;
}
