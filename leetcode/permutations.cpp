/*

 Permutations

 Given a collection of numbers, return all possible permutations.

 For example,
 [1,2,3] have the following permutations:
 [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].

 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void dfs(vector<int> &num, vector<vector<int>> &res, int index,
             int n)
    {
        if (index == n) {
            res.push_back(num);
        } else {
            for (int i = index; i < n; i++) {
                swap(num[index], num[i]);
                dfs(num, res, index + 1, n);
                swap(num[index], num[i]);
            }
        }
    }

    vector<vector<int> > permute(vector<int> &num)
    {
        vector<vector<int>> ret;
        dfs(num, ret, 0, num.size());
        return ret;
    }
};

int main(int argc, char* argv[])
{
    vector<int> v = { 1, 2, 3 };
    Solution sol;

    vector<vector<int>> res = sol.permute(v);
    for (auto &v1 : res) {
        for (auto t : v1)
            cout << t << ends;
        cout << endl;
    }

    return 0;
}
