/*
 Remove Element

 Given an array and a value, remove all instances of that value
 in place and return the new length.

 The order of elements can be changed.
 It doesn't matter what you leave beyond the new length.

 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeElement(int A[], int n, int elem)
    {
        if (n <= 0)
            return n; //

        if (n == 1)
            return A[0] == elem ? 0 : 1;

        int start = 0, end = n - 1;
        while (start < end) {
            if (A[start] != elem) {
                start++;
            } else if (A[end] == elem) {
                end--;
            } else {
                swap(A[start], A[end]);
                start++;
                end--;
            }
        }
        return start + (A[start] == elem ? 0 : 1); //
    }

    int removeElement2(int A[], int n, int elem)
    {
        int i = 0, j = 0;
        while (j < n) {
            if (A[j] != elem) A[i++] = A[j];
            j++;
        }
        return i;
    }
};

int main(int argc, char *argv[])
{
    int a[] = { 3, 3, 5, 4, 5 };
    Solution sol;

    cout << sol.removeElement(a, sizeof(a) / sizeof(int), 5) << endl;

    for (auto t : a)
        cout << t << ends;

    return 0;
}
