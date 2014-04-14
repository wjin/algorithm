/*

 Combinations

 Given two integers n and k, return all possible combinations
 of k numbers out of 1 ... n.

 For example,
 If n = 4 and k = 2, a solution is:

 [
 [2,4],
 [3,4],
 [2,3],
 [1,2],
 [1,3],
 [1,4],
 ]

 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void dfs(vector<vector<int> > &ret, vector<int> &selection,
             int n, int k)
    {
        if (k == 0) {
            ret.push_back(selection);
        } else {
            // choose n, and select k - 1 elements from 1...n-1
            for (int i = n; i >= k; i--) {
                selection.push_back(i); // choose
                dfs(ret, selection, i - 1, k - 1);  // i - 1
                selection.pop_back(); // not choose
            }
        }
    }

    vector<vector<int> > combine(int n, int k)
    {
        vector<vector<int> > ret;
        vector<int> selection;

        dfs(ret, selection, n, k);
        return ret;
    }
};

// iterative
class Solution2
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> num(n);
        iota(begin(num), end(num), 1);

        vector<vector<int>> ret;
        vector<int> selection;
        vector<bool> tag(n, 0);
        fill_n(begin(tag), k, 1);

        do {
            for (int i = 0; i < n; i++) {
                if (tag[i]) selection.push_back(num[i]);
            }

            ret.push_back(selection);
            selection.clear();
        } while (prev_permutation(begin(tag), end(tag)));
        return ret;
    }
};

void print_ret(vector<vector<int>> &v)
{
    cout << endl;
    for (auto &v1 : v) {
        for (auto t : v1)
            cout << t << ' ';
        cout << endl;
    }
}

int main(int argc, char* argv[])
{
    Solution sol;
    Solution2 sol2;

    vector<vector<int>> ret = sol.combine(4, 2);
    print_ret(ret);

    ret = sol2.combine(4, 2);
    print_ret(ret);

    return 0;
}
