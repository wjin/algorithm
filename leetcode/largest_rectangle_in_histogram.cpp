/*

Largest Rectangle in Histogram

Given n non-negative integers representing the histogram's bar height
where the width of each bar is 1, find the area of largest rectangle in the histogram.

For example,
Given height = [2,1,5,6,2,3],
return 10.

*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &height)
    {
        int len = height.size();
        if (len <= 0) return 0;

        stack<int> stk;
        int ret = 0;
        height.push_back(-1); // use -1 to pop remaining all elements

        // traverse each element
        // if stack is empty or height[i] is bigger than stack top element
        // push it to stack.
        // otherwise, pop stack and calculte temp result
        // actually, we will keep the minimum element in the stack in the end
        // so use -1 to pop it out
        int i = 0;
        while (i <= len) { // = means one more element -1
            if (stk.empty() || height[i] > height[stk.top()]) {
                stk.push(i++);
            } else { // element is less than or equal to stack top element
                int index = stk.top();
                stk.pop();

                // if stack is empty, height[i] is the minimum element from height[0...i]
                int width = stk.empty() ? i : i - stk.top() - 1;
                ret = max(ret, height[index] * width);
            }
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> height = {2,1,5,6,2,3};

    cout << sol.largestRectangleArea(height) << endl;

    return 0;
}
