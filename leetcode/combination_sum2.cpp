/*

 Combination Sum II

 Given a collection of candidate numbers (C) and a target number (T),
 find all unique combinations in C where the candidate numbers sums to T.

 Each number in C may only be used once in the combination.

 Note:
 All numbers (including target) will be positive integers.
 Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).

 The solution set must not contain duplicate combinations.

 For example, given candidate set 10,1,2,7,6,1,5 and target 8,
 A solution set is:
 [1, 7]
 [1, 2, 5]
 [2, 6]
 [1, 1, 6]

 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution
{
public:
    void dfs(vector<int> &candidates, int start, int end,
             set<vector<int> > &ret, vector<int> &selection, int target)
    {
        if (target == 0) {
            ret.insert(selection);
        } else if (start <= end) {
            for (int i = start; i <= end; i++) {
                int t = target - candidates[i];
                if (t >= 0) {
                    selection.push_back(candidates[i]);
                    dfs(candidates, i + 1, end, ret, selection, t);
                    selection.pop_back();
                }
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &num, int target)
    {
        vector<int> selection;
        set<vector<int>> ret;

        // sort to make sure small numbers are present first
        sort(num.begin(), num.end());
        dfs(num, 0, num.size() - 1, ret, selection, target);
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

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> num = { 10, 1, 2, 7, 6, 1, 5 };

    vector<vector<int>> ret = sol.combinationSum2(num, 8);
    print_ret(ret);

    return 0;
}
