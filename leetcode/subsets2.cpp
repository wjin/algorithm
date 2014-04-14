/*

 Subsets II:

 Given a collection of integers that might contain duplicates, S,
 return all possible subsets.

 Note:

 Elements in a subset must be in non-descending order.
 The solution set must not contain duplicate subsets.
 For example,
 If S = [1,2,2], a solution is:

 [
 [2],
 [1],
 [1,2,2],
 [2,2],
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
#if 0
            // judge whether it is a repeating number
            bool isDuplicate = false;
            for (int j = start; j < i; j++) {
                if (v[j] == v[i])
                    isDuplicate = true;
            }
#endif
            // v is sorted, so we can judge duplicate
            // by only comparing with previous element
            if (i > start && v[i] == v[i - 1]) continue;

            selection.push_back(v[i]);
            ret.push_back(selection);
            get_non_empty_subset(v, i + 1, end, ret, selection);
            selection.pop_back();
        }
    }

    vector<vector<int> > subsetsWithDup(vector<int> &v)
    {
        vector<vector<int> > ret;
        vector<int> selection;

        sort(v.begin(), v.end()); //make sure small numbers are present first
        ret.push_back(selection); // add empty subset first
        get_non_empty_subset(v, 0, v.size() - 1, ret, selection);

        return ret;
    }
};

// iterative
class Solution2
{
public:
    vector<vector<int> > subsetsWithDup(vector<int> &v)
    {
        vector<vector<int>> ret(1);
        sort(v.begin(), v.end()); //make sure small numbers are present first

        size_t previous_size = 0; // avoid duplicate

        for (size_t i = 0; i < v.size(); i++) {
            size_t curSize = ret.size();
            // do a copy of current elements and then add one number
            // to each copied element if no duplicate
            // the original elements mean we do not choose current number
            // the copied one mean we choose current number
            for (size_t j = 0; j < curSize; j++) {
                // if v[i-1]=v[i] and j<previous_size, we do not extend element
                // as it is duplicate
                if (i == 0 || v[i - 1] != v[i] || j >= previous_size) {
                    ret.push_back(ret[j]); // add one more element
                    ret.back().push_back(v[i]); // extend it
                }
            }

            previous_size = curSize; // not ret.size()
        }
        return ret;
    }
};

void print_ret(vector<vector<int>> &v)
{
    for (auto &row : v) {
        for (auto col : row)
            cout << col << ' ';
        cout << endl;
    }
}

int main(int argc, char* argv[])
{
    vector<int> v = { 1, 2, 2 };
    Solution sol;
    Solution2 sol2;

    vector<vector<int>> ret = sol.subsetsWithDup(v);
    print_ret(ret);

    ret = sol2.subsetsWithDup(v);
    print_ret(ret);

    return 0;
}
