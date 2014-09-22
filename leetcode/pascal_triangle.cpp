/*

 Pascal's Triangle

 Given numRows, generate the first numRows of Pascal's triangle.

 For example, given numRows = 5,
 Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int> > generate(int numRows)
    {
        if (numRows == 0)
            return vector<vector<int> >();

        vector<vector<int> > ret(numRows);
        ret[0].push_back(1);
        for (int i = 1; i < numRows; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0) // first element
                    ret[i].push_back(ret[i - 1][j]);
                else if (j == i) // last element
                    ret[i].push_back(ret[i - 1][j - 1]);
                else // middle elment
                    ret[i].push_back(ret[i - 1][j - 1] + ret[i - 1][j]);
            }
        }

        return ret;
    }
};

class Solution2
{
public:
    vector<vector<int> > generate(int numRows)
    {
        vector<vector<int> > ret;
        if (numRows <= 0) return ret;

        ret.push_back(vector<int>(1, 1));
        for (int i = 1; i < numRows; i++) {
            ret.push_back(vector<int>(i + 1, 0));
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i) {
                    ret[i][j] = 1;
                } else {
                    ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
                }
            }
        }

        return ret;
    }
};

void print(vector<vector<int>> v)
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
    Solution2 sol2;

    print(sol.generate(5));
    print(sol2.generate(5));

    return 0;
}
