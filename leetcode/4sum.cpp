/*

 4Sum

 Given an array S of n integers, are there elements a, b, c, and d in S
 such that a + b + c + d = target? Find all unique quadruplets in the array
 which gives the sum of target.

 Note:

 Elements in a quadruplet (a,b,c,d) must be in non-descending order.
 (ie, a <= b <= c <= d) The solution set must not contain duplicate
 quadruplets.

 For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

 A solution set is:
 (-1,  0, 0, 1)
 (-2, -1, 1, 2)
 (-2,  0, 0, 2)

 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // O(n^3)
    vector<vector<int> > fourSum(vector<int> &num, int target)
    {
        set<vector<int> > ret; //eliminate duplicate cases
        int i, j, len = num.size();

        sort(num.begin(), num.end());
        for (i = 0; i < len - 3; i++) {
            for (j = i + 1; j < len - 2; j++) {
                int start = j + 1, end = len - 1;
                int sum = 0;
                // two pointers move toward each other. O(n)
                while (start < end) {
                    sum = num[i] + num[j] + num[start] + num[end];
                    if (sum == target) {
                        vector<int> selection = { num[i], num[j], num[start],
                                                  num[end]
                                                };
                        ret.insert(selection);
                        //continue find other combinations leading with num[i] such that sum == 0
                        start++;
                        end--;
                    } else if (sum < target) {
                        start++;
                    } else {
                        end--;
                    }
                }
            }
        }

        return vector<vector<int>>(ret.begin(), ret.end());
    }
};

void print_ret(vector<vector<int>> &v)
{
    for (auto &v1 : v) {
        for (auto t : v1)
            cout << t << ends;
        cout << endl;
    }
}

int main(int argc, char* argv[])
{
    vector<int> v = { 1, 0, -1, 0, -2, 2 };
    int target = 0;
    Solution sol;

    vector<vector<int> > ret = sol.fourSum(v, target);
    print_ret(ret);

    return 0;
}
