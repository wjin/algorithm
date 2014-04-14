/*

 Search in Rotated Sorted Array

 Suppose a sorted array is rotated at some pivot unknown to you beforehand.

 (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

 You are given a target value to search.
 If found in the array return its index, otherwise return -1.

 You may assume no duplicate exists in the array.

 */

#include <iostream>

using namespace std;

// O(log n)
class Solution
{
public:
    int search(int A[], int n, int target)
    {
        int low = 0, high = n - 1;
        int mid = 0;
        while (low <= high) {
            mid = low + ((high - low) >> 1);
            if (A[mid] == target)
                return mid;
            else { // A[mid] != target
                if (A[low] <= A[mid]) { // elements in the first part is in order
                    // || means A[mid] > target && A[low] > target
                    // also note here A[mid] != target
                    if (A[mid] < target || A[low] > target) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                } else { // elements in the second part is in order
                    if (A[mid] > target || A[high] < target) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
        }
        return -1;
    }

    int search2(int A[], int n, int target)
    {
        int low = 0, high = n - 1;
        int mid = 0;
        while (low <= high) {
            mid = low + ((high - low) >> 1);
            if (A[mid] == target)
                return mid;
            else { // A[mid] != target
                if (A[low] <= A[mid]) { // elements in the first part is in order
                    if (A[low] <= target && target < A[mid]) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                } else { // elements in the second part is in order
                    if (A[mid] < target && target <= A[high]) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                }
            }
        }
        return -1;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    int a[] = { 4, 5, 6, 7, 0, 1, 2 };

    cout << sol.search(a, sizeof(a) / sizeof(int), 4) << endl;
    cout << sol.search(a, sizeof(a) / sizeof(int), 7) << endl;
    cout << sol.search(a, sizeof(a) / sizeof(int), 0) << endl;
    cout << sol.search(a, sizeof(a) / sizeof(int), 1) << endl;
    cout << sol.search(a, sizeof(a) / sizeof(int), 3) << endl;

    cout << sol.search2(a, sizeof(a) / sizeof(int), 4) << endl;
    cout << sol.search2(a, sizeof(a) / sizeof(int), 7) << endl;
    cout << sol.search2(a, sizeof(a) / sizeof(int), 0) << endl;
    cout << sol.search2(a, sizeof(a) / sizeof(int), 1) << endl;
    cout << sol.search2(a, sizeof(a) / sizeof(int), 3) << endl;

    return 0;
}
