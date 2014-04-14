/*

 Combination Sum

 Given a set of candidate numbers (C) and a target number (T), find all unique
 combinations in C where the candidate numbers sums to T.
 The same repeated number may be chosen from C unlimited number of times.

 Note:
 1）	All numbers (including target) will be positive integers.
 2）	Elements in a combination (a1, a2, a3,…, ak) must be in non-descending order.
 (ie, a1 <= a2 <= a3 <=… <= ak).
 The solution set must not contain duplicate combinations.

 For example, given candidate set 2,3,6,7 and target 7,
 A solution set is:
 [7]
 [2, 2, 3]

 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void dfs(vector<int> &candidates, int start, int end,
             vector<vector<int> > &ret, vector<int> &selection, int target)
    {
        if (target == 0) {
            ret.push_back(selection);
        } else {
            for (int i = start; i <= end; i++) {
                int t = target - candidates[i];
                if (t >= 0) {
                    selection.push_back(candidates[i]);
                    dfs(candidates, i, end, ret, selection, t);
                    selection.pop_back();
                }
            }
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int> > ret;
        vector<int> selection;

        // sort to make sure small numbers are present first
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, candidates.size() - 1, ret, selection, target);
        return ret;
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
    vector<int> v = { 7, 6, 3, 2 };
    int target = 7;
    Solution sol;

    vector<vector<int>> ret = sol.combinationSum(v, target);
    print_ret(ret);

    return 0;
}
