/*

 Search in Rotated Sorted Array ||

 Follow up for "Search in Rotated Sorted Array":
 What if duplicates are allowed?

 Would this affect the run-time complexity? How and why?

 Write a function to determine if a given target is in the array.

 */

#include <iostream>

using namespace std;

// O(n)
class Solution
{
public:
    bool search(int A[], int n, int target)
    {
        int low = 0, high = n - 1;
        int mid = 0;
        while (low <= high) {
            mid = low + ((high - low) >> 1);
            if (A[mid] == target)
                return true;
            else { // A[mid] != target
                if (A[low] <= A[mid]) {
                    if (A[low] == A[mid]) {
                        // simply add first subscript...
                        // I cannot find good way to deal with it. :(
                        // does it still exist O(log n) algorithm?
                        low++;
                        continue;
                    }

                    // otherwise, elements in the first part is in order
                    // || means A[mid] > target && A[low] > target
                    // also note here A[mid] != target
                    if (A[mid] < target || A[low] > target) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                } else { // A[low] > A[mid]
                    // elements in the second part is in order
                    if (A[mid] > target || A[high] < target) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
            }
        }
        return false;
    }

    bool search2(int A[], int n, int target)
    {
        int low = 0, high = n - 1;
        int mid = 0;
        while (low <= high) {
            mid = low + ((high - low) >> 1);
            if (A[mid] == target)
                return true;
            else { // A[mid] != target
                if (A[low] < A[mid]) {
                    if (A[low] <= target && target < A[mid]) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                } else if (A[low] > A[mid]) {
                    // elements in the second part is in order
                    if (A[mid] < target && target <= A[high]) {
                        low = mid + 1;
                    } else {
                        high = mid - 1;
                    }
                } else { // A[low] = A[mid], duplicate occur
                    if (A[mid] == A[high]) { // low, mid and high are equal
                        low++; // simply let low + 1
                    } else { // left...mid are equal, just search right side
                        low = mid + 1;
                    }
                }
            }
        }
        return false;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    int a[] = { 4, 5, 6, 7, 0, 1, 1, 1, 2 };
    int a2[] = { 1, 1, 3 };
    int a3[] = { 1, 1, 3, 1 };

    cout << sol.search(a, sizeof(a) / sizeof(int), 4) << endl;
    cout << sol.search(a, sizeof(a) / sizeof(int), 7) << endl; // bug
    cout << sol.search(a, sizeof(a) / sizeof(int), 0) << endl;
    cout << sol.search(a, sizeof(a) / sizeof(int), 1) << endl;
    cout << sol.search(a, sizeof(a) / sizeof(int), 3) << endl;
    cout << sol.search(a2, sizeof(a2) / sizeof(int), 3) << endl; // bug
    cout << sol.search(a3, sizeof(a3) / sizeof(int), 3) << endl; // bug

    cout << sol.search2(a, sizeof(a) / sizeof(int), 4) << endl;
    cout << sol.search2(a, sizeof(a) / sizeof(int), 7) << endl;
    cout << sol.search2(a, sizeof(a) / sizeof(int), 0) << endl;
    cout << sol.search2(a, sizeof(a) / sizeof(int), 1) << endl;
    cout << sol.search2(a, sizeof(a) / sizeof(int), 3) << endl;
    cout << sol.search2(a2, sizeof(a2) / sizeof(int), 3) << endl;
    cout << sol.search2(a3, sizeof(a3) / sizeof(int), 3) << endl;

    return 0;
}
