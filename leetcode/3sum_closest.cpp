/*

 3Sum Closest

 Given an array S of n integers, find three integers in S such that the sum is
 closest to a given number, target. Return the sum of the three integers.
 You may assume that each input would have exactly one solution.

 For example, given array S = {-1 2 1 -4}, and target = 1.

 The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &num, int target)
    {
        int len = num.size();
        if (len <= 2) //invalid
            return -1;

        sort(num.begin(), num.end());
        // long long, otherwise, closestSum - target might be overflow
        long long closestSum = INT_MAX;
        int sum = 0;
        int diff = 0;
        int start = 0, end = 0;
        for (int i = 0; i < len - 2; i++) {
            start = i + 1, end = len - 1;
            // two pointers move toward each other. O(n)
            while (start < end) {
                sum = num[i] + num[start] + num[end];
                diff = sum - target;
                if (abs(diff) < abs(closestSum - target)) {
                    closestSum = sum;
                }
                if (diff < 0) {
                    start++;
                } else if (diff > 0) {
                    end--;
                } else {
                    return closestSum;
                }
            }
        }

        return closestSum;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v1 = { -1, 2, 1, -4 };
    vector<int> v2 = { 0, 2, 1, -3 };
    vector<int> v3 = { 1, 1, -1, -1, 3 };

    cout << sol.threeSumClosest(v1, 1) << endl;
    cout << sol.threeSumClosest(v2, 1) << endl;
    cout << sol.threeSumClosest(v3, -1) << endl;

    return 0;
}
