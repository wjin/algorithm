/*

Container With Most Water

Given n non-negative integers a1, a2, ..., an, where each represents a point at
coordinate (i, ai). n vertical lines are drawn such that the two endpoints of
line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms
a container, such that the container contains the most water.

Note: You may not slant the container.

 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // greedy algorithm
    int maxArea(vector<int> &height)
    {
        int maxAreaSize = 0;
        int i = 0, j = height.size() - 1;

        while (i < j) {
            int area = (j - i) * min(height[i], height[j]);
            maxAreaSize = max(area, maxAreaSize);

            // assume height[i] <= height[j], it means height is fixed
            // areas with other lines can not be bigger than with j as they are close to i
            if (height[i] <= height[j]) i++;
            else j--;
        }

        return maxAreaSize;
    }
};

int main(int argc, char* argv[])
{
    vector<int> v = { 1, 2, 3 };
    Solution sol;

    cout << sol.maxArea(v) << endl;

    return 0;
}
