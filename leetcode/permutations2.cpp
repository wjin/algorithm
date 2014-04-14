/*

 Permutations II

 Given a collection of numbers that might contain duplicates,
 return all possible unique permutations.

 For example,
 [1,1,2] have the following unique permutations:
 [1,1,2], [1,2,1], and [2,1,1].

 */

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // use set container to eliminate duplicate result
    void dfs1(vector<int> &num, set<vector<int>> &ret, int index,
              int n)
    {
        if (index == n) {
            ret.insert(num);
        } else {
            for (int i = index; i < n; i++) {
                swap(num[index], num[i]);
                dfs1(num, ret, index + 1, n);
                swap(num[index], num[i]);
            }
        }
    }
    vector<vector<int> > permute1(vector<int> &num)
    {
        vector<vector<int>> ret;
        set<vector<int>> tmp;

        dfs1(num, tmp, 0, num.size());
        ret.assign(tmp.begin(), tmp.end());
        return ret;
    }

    // do not generate duplicate result directly
    void dfs2(vector<int> &num, vector<vector<int>> &ret, int index,
              int n)
    {
        if (index == n) {
            ret.push_back(num);
        } else {
            for (int i = index; i < n; i++) {
                // we cannot sort array first and then just compare with previous element
                // like we did in subset ||, becuase we swapped array before, so that way
                // does not work.

                // verify that element i is not the same to element from 'index to i-1'
                bool isDuplicate = false;
                for (int j = index; j < i; j++) {
                    if (num[j] == num[i]) {
                        isDuplicate = true;
                        break;
                    }
                }
                if (!isDuplicate) {
                    swap(num[index], num[i]);
                    dfs2(num, ret, index + 1, n);
                    swap(num[index], num[i]);
                }
            }
        }
    }
    vector<vector<int> > permute2(vector<int> &num)
    {
        vector<vector<int>> ret;
        dfs2(num, ret, 0, num.size());
        return ret;
    }

    // use stl algorithm to do it
    vector<vector<int> > permute3(vector<int> &num)
    {
        vector<vector<int>> ret;

        sort(num.begin(), num.end());
        do {
            ret.push_back(num);
        } while (next_permutation(num.begin(), num.end()));

        return ret;
    }
};

void print_ret(vector<vector<int>> &v)
{
    cout << endl;
    for (auto &v1 : v) {
        for (auto t : v1)
            cout << t << ends;
        cout << endl;
    }
}

int main(int argc, char* argv[])
{
    vector<int> v = { 1, 1, 2 };
    Solution sol;

    vector<vector<int>> ret1 = sol.permute1(v);
    vector<vector<int>> ret2 = sol.permute2(v);
    vector<vector<int>> ret3 = sol.permute3(v);

    print_ret(ret1);
    print_ret(ret2);
    print_ret(ret3);

    return 0;
}
