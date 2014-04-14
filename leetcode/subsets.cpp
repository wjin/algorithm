/*

 Subsets

 Given a set of distinct integers, S, return all possible subsets.

 Note:

 Elements in a subset must be in non-descending order.
 The solution set must not contain duplicate subsets.

 For example,
 If S = [1,2,3], a solution is:

 [
 [3],
 [1],
 [2],
 [1,2,3],
 [1,3],
 [2,3],
 [1,2],
 []
 ]

 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void get_non_empty_subset(vector<int> &v, int start, int end,
                              vector<vector<int> > &ret, vector<int> &selection)
    {
        for (int i = start; i <= end; i++) {
            selection.push_back(v[i]);
            ret.push_back(selection);
            get_non_empty_subset(v, i + 1, end, ret, selection);
            selection.pop_back();
        }
    }

    vector<vector<int> > subsets(vector<int> &v)
    {
        vector<vector<int> > ret;
        vector<int> selection;

        sort(v.begin(), v.end()); // make sure small numbers are present first
        ret.push_back(selection); // add empty subset first
        get_non_empty_subset(v, 0, v.size() - 1, ret, selection);

        return ret;
    }
};

// iterative
class Solution2
{
public:
    vector<vector<int> > subsets(vector<int> &v)
    {
        sort(v.begin(), v.end()); // make sure small numbers are present first
        vector<vector<int> > ret(1); // initial state, one empty subset

        ret.reserve(pow(2, v.size())); // avoid reallocation, which will lead to copy/for_each crash
        for (auto e : v) {
            auto end = ret.end();
            copy(ret.begin(), end, back_inserter(ret));
            for_each(end, ret.end(), [&e](vector<int> &t) {
                t.push_back(e);
            });
        }

        return ret;
    }
};

void print_ret(vector<vector<int>> &v)
{
    for (auto &row : v) {
        for (auto col : row)
            cout << col << ' ' ;
        cout << endl;
    }
}

int main(int argc, char* argv[])
{
    vector<int> v = { 3, 1, 2 };
    Solution sol;
    Solution2 sol2;

    vector<vector<int>> ret = sol.subsets(v);
    print_ret(ret);

    ret = sol2.subsets(v);
    print_ret(ret);

    return 0;
}
