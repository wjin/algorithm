/*

 Sort Colors

 Given an array with n objects colored red, white or blue, sort them so that
 objects of the same color are adjacent, with the colors in the order red, white and blue.

 Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

 Note:
 You are not suppose to use the library's sort function for this problem.

 click to show follow up.

 Follow up:
 A rather straight forward solution is a two-pass algorithm using counting sort.
 First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array
 with total number of 0's, then 1's and followed by 2's.

 Could you come up with an one-pass algorithm using only constant space?

 */

#include <iostream>

using namespace std;

class Solution
{
public:
    void sortColors(int A[], int n)
    {
        int i = 0; // red
        int j = n - 1; // white
        int k = n - 1; // blue

        while (i <= j) { // =; bug, a2
            if (A[i] == 0)
                i++; // red
            else if (A[i] == 1) { // white
                swap(A[i], A[j]);
                j--;
            } else { // A[i] == 2
                swap(A[i], A[k]);
                k--;
                if (j > k)
                    j = k;
            }
        }
    }

    void sortColors2(int A[], int n)
    {
        int red = 0, blue = n - 1;
        int i = 0;
        while (i <= blue) {
            if (A[i] == 0) swap(A[i++], A[red++]);
            else if (A[i] == 2) swap(A[i], A[blue--]); // not i++
            else i++;
        }
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    int a[] = { 1, 2, 0, 0, 1, 2, 2 };
    int a2[] = { 1, 2 }; //

    sol.sortColors(a, sizeof(a) / sizeof(int));
    sol.sortColors(a2, sizeof(a2) / sizeof(int));

    for (auto s : a)
        cout << s << ends;
    cout << endl;

    for (auto s : a2)
        cout << s << ends;
    cout << endl;

    return 0;
}
