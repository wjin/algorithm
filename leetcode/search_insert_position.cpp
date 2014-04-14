/*

 Search Insert Position

 Given a sorted array and a target value, return the index if the target is found.
 If not, return the index where it would be if it were inserted in order.

 You may assume no duplicates in the array.

 Here are few examples.
 [1,3,5,6], 5 → 2
 [1,3,5,6], 2 → 1
 [1,3,5,6], 7 → 4
 [1,3,5,6], 0 → 0

 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int searchInsert(int A[], int n, int target)
    {
        if (n <= 0)
            return -1;

        int i;
        for (i = 0; i < n; i++) {
            if (A[i] == target)
                return i;
            if (A[i] > target)
                break;
        }

        return i;
    }

    int searchInsert2(int A[], int n, int target)
    {
        if (n <= 0)
            return -1;

        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (A[mid] == target) return mid;
            else if (target > A[mid]) low = mid + 1;
            else high = mid - 1;

        }

        return low;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    int a[] = { 1, 3, 5, 6 };

    cout << sol.searchInsert(a, sizeof(a) / sizeof(int), 5) << endl;
    cout << sol.searchInsert(a, sizeof(a) / sizeof(int), 2) << endl;
    cout << sol.searchInsert(a, sizeof(a) / sizeof(int), 7) << endl;
    cout << sol.searchInsert(a, sizeof(a) / sizeof(int), 0) << endl;

    cout << sol.searchInsert2(a, sizeof(a) / sizeof(int), 5) << endl;
    cout << sol.searchInsert2(a, sizeof(a) / sizeof(int), 2) << endl;
    cout << sol.searchInsert2(a, sizeof(a) / sizeof(int), 7) << endl;
    cout << sol.searchInsert2(a, sizeof(a) / sizeof(int), 0) << endl;

    return 0;
}
