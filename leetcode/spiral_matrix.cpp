/*

   Spiral Matrix

   Given a matrix of m x n elements (m rows, n columns),
   return all elements of the matrix in spiral order.

   For example,
   Given the following matrix:

   [
   [ 1, 2, 3 ],
   [ 4, 5, 6 ],
   [ 7, 8, 9 ]
   ]

   You should return [1,2,3,6,9,8,7,4,5].

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ret;
        int m = matrix.size();
        if (m == 0) return ret;
        int n = matrix[0].size();

        // don't compare int with size_t as there may be negative number
        int total = m * n;
        int cycle = 0; // not size_t
        int i = 0, j = 0;
        while (total) {
            // right
            j = 0; // be careful to start next cycle
            for (j = j + cycle; j < n - cycle; j++) {
                ret.push_back(matrix[i][j]);
                total--;
                if (total == 0) return ret;
            }
            j--; // let j valid

            // down
            for (i = cycle + 1; i < m - cycle; i++) {
                ret.push_back(matrix[i][j]);
                total--;
                if (total == 0) return ret;
            }
            i--;

            // left
            for (j = n - cycle - 2; j >= cycle; j--) {
                ret.push_back(matrix[i][j]);
                total--;
                if (total == 0) return ret;
            }
            j++;

            // up
            for (i = m - cycle - 2; i > cycle; i--) {
                ret.push_back(matrix[i][j]);
                total--;
                if (total == 0) return ret;
            }
            i++;

            cycle++;
        }

        return ret;
    }

};

// clear code from internet
class Solution2
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ret;
        if (matrix.empty()) return ret;

        int rowStart = 0, rowEnd = matrix.size() - 1;
        int colStart = 0, colEnd = matrix[0].size() - 1;

        while (true) {
            for (int j = colStart; j <= colEnd; j++) {
                ret.push_back(matrix[rowStart][j]);
            }
            if (++rowStart > rowEnd) break;

            for (int i = rowStart; i <= rowEnd; i++) {
                ret.push_back(matrix[i][colEnd]);
            }
            if (--colEnd < colStart) break;

            for (int j = colEnd; j >= colStart; j--) {
                ret.push_back(matrix[rowEnd][j]);
            }
            if (--rowEnd < rowStart) break;

            for (int i = rowEnd; i >= rowStart; i--) {
                ret.push_back(matrix[i][colStart]);
            }
            if (++colStart > colEnd) break;
        }
        return ret;
    }
};

void print_ret(vector<int> &ret)
{
    for (auto e : ret)
        cout << e << ' ';
    cout << endl;
}

int main(int argc, char *argv[])
{
    Solution sol;
    Solution2 sol2;
    vector<vector<int>> matrix = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
    vector<vector<int>> matrix2 = { { 2, 3 } };
    vector<vector<int>> matrix3 = { {1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20}, {21,22,23,24,25} };

    vector<int> ret;

    ret = sol.spiralOrder(matrix);
    print_ret(ret);

    ret = sol.spiralOrder(matrix2);
    print_ret(ret);

    ret = sol.spiralOrder(matrix3);
    print_ret(ret);

    ret = sol2.spiralOrder(matrix);
    print_ret(ret);

    ret = sol2.spiralOrder(matrix2);
    print_ret(ret);

    ret = sol2.spiralOrder(matrix3);
    print_ret(ret);

    return 0;
}
