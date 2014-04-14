/*

 Search for a Range

 Given a sorted array of integers, find the starting and ending
 position of a given target value.

 Your algorithm's runtime complexity must be in the order of O(log n).

 If the target is not found in the array, return [-1, -1].

 For example,
 Given [5, 7, 7, 8, 8, 10] and target value 8,
 return [3, 4].

 */

#include <iostream>
#include <vector>

using namespace std;

// O(log n)
class Solution
{
public:
    bool find(int a[], int n, int target, int &ret, bool isLeft)
    {
        int low = 0, high = n - 1;
        int mid = 0;
        while (low <= high) {
            mid = low + (high - low) / 2;

            if (a[mid] > target)
                high = mid - 1;
            else if (a[mid] < target)
                low = mid + 1;
            else { // a[mid] == target
                if (isLeft) { // find lower bound
                    if (a[low] == target) {
                        ret = low;
                        return true;
                    }
                    // update boundary to continue find
                    low += 1;
                    high = mid;
                } else { // find upper bound
                    if (a[high] == target) {
                        ret = high;
                        return true;
                    }
                    low = mid;
                    high -= 1;
                }
            }
        }
        return false;
    }

    vector<int> searchRange(int A[], int n, int target)
    {
        int left = -1, right = -1;
        if (find(A, n, target, left, true)) find(A, n, target, right, false);
        vector<int> ret = { left, right };
        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    int a[] = { 5, 7, 7, 8, 8, 10 };

    vector<int> ret = sol.searchRange(a, sizeof(a) / sizeof(int), 8);
    cout << ret[0] << ' ' << ret[1] << endl;

    ret = sol.searchRange(a, sizeof(a) / sizeof(int), 5);
    cout << ret[0] << ' ' << ret[1] << endl;

    return 0;
}
