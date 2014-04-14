/*

   Maximal Rectangle

   Given a 2D binary matrix filled with 0's and 1's,
   find the largest rectangle containing all ones and return its area.

*/

#include <iostream>
#include <vector>

using namespace std;

// this solution from leetecode discussion
class Solution
{
public:
    int maximalRectangle(vector<vector<char> > &matrix)
    {
        const int m = matrix.size();
        if (m == 0) return 0;

        const int n = matrix[0].size();
        vector<int> H(n, 0); // height
        vector<int> L(n, 0); // track left 0 (obstacle)
        vector<int> R(n, n); // track right 0 (obstacle)

        int ret = 0;
        // traverse all "hanging line", total lines: (m - 1) * n
        for (int i = 0; i < m; ++i) {
            int left = 0, right = n;
            // calculate L(i, j) from left to right
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == '1') {
                    ++H[j];
                    L[j] = max(L[j], left);
                } else {
                    // use left to control current row traverse
                    left = j + 1;

                    // here means hanging line is cut
                    // next row will start from scratch, cannot combine
                    // area with previous row (the same column hanging line)
                    H[j] = 0;
                    L[j] = 0; //
                    R[j] = n; //
                }
            }

            // calculate R(i, j) from right to left
            for (int j = n-1; j >= 0; --j) {
                if (matrix[i][j] == '1') {
                    R[j] = min(R[j], right);
                    ret = max(ret, H[j]*(R[j]-L[j]));
                } else {
                    right = j;
                }
            }
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    vector<vector<char>> matrix = { {'0','0', '0', '0'}, {'0', '0', '1', '0'}, {'0', '1', '0', '1'} };
    vector<vector<char>> matrix2 = { {'0','1'}, {'1', '0'} };
    vector<vector<char>> matrix3 = { {'1','1'} };

    cout << sol.maximalRectangle(matrix) << endl;
    cout << sol.maximalRectangle(matrix2) << endl;
    cout << sol.maximalRectangle(matrix3) << endl;

    return 0;
}
