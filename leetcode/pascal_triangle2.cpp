/*

 Pascal's Triangle ||

 Given an index k, return the kth row of the Pascal's triangle.

 For example, given k = 3,
 Return [1,3,3,1].

 Note:
 Could you optimize your algorithm to use only O(k) extra space?
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // O(k) space complexity
    vector<int> getRow(int rowIndex)
    {
        vector<int> ret(rowIndex + 1);

        ret[0] = 1;
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = i; j >= 0; j--) { // back to front
                if (j == 0)
                    continue;
                else if (j == i)
                    ret[j] = ret[j - 1];
                else
                    ret[j] = ret[j - 1] + ret[j];
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    vector<int> ret = sol.getRow(3);

    for (auto t : ret)
        cout << t << ends;

    return 0;
}
