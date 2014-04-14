/*

 3sum

 Given an array S of n integers, are there elements a, b, c in S
 such that a + b + c = 0? Find all unique triplets in the array
 which gives the sum of zero.

 Note:

 Elements in a triplet (a,b,c) must be in non-descending order. (ie, a <= b <= c)
 The solution set must not contain duplicate triplets.
 For example, given array S = {-1 0 1 2 -1 -4},

 A solution set is:
 (-1, 0, 1)
 (-1, -1, 2)

 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // O(n^2)
    vector<vector<int> > threeSum(vector<int> &num)
    {
        set<vector<int> > ret; //eliminate duplicate solution
        int i = 0, len = num.size();

        sort(num.begin(), num.end());
        for (i = 0; i < len - 2; i++) {
            int start = i + 1, end = len - 1;
            int sum = 0;
            // two pointers move toward each other. O(n)
            while (start < end) {
                sum = num[i] + num[start] + num[end];
                if (sum == 0) {
                    vector<int> selection = { num[i], num[start], num[end] };
                    ret.insert(selection);
                    //continue find other combinations leading with num[i] such that sum == 0
                    start++;
                    end--;
                } else if (sum < 0) {
                    start++;
                } else {
                    end--;
                }
            }
        }
        return vector<vector<int>>(ret.begin(), ret.end());
    }
};

void print_ret(vector<vector<int>> &v)
{
    for (auto &row : v) {
        for (auto col : row)
            cout << col << ends;
        cout << endl;
    }
}

int main(int argc, char* argv[])
{
    vector<int> v = { -1, 0, 1, 2, -1, -4 };
    Solution sol;

    vector<vector<int> > ret = sol.threeSum(v);
    print_ret(ret);

    return 0;
}
