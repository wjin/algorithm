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

   Xou should return [1,2,3,6,9,8,7,4,5].

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
        if (matrix.empty()) return ret;

        int begX = 0, endX = matrix[0].size() - 1;
        int begY = 0, endY = matrix.size() - 1;

        while (true) {
            // left to right
            for (int j = begX; j <= endX; j++) {
                ret.push_back(matrix[begY][j]);
            }
            if (++begY > endY) break;

            // up to bottom
            for (int i = begY; i <= endY; i++) {
                ret.push_back(matrix[i][endX]);
            }
            if (--endX < begX) break;

            // right to left
            for (int j = endX; j >= begX; j--) {
                ret.push_back(matrix[endY][j]);
            }
            if (--endY < begY) break;

            // bottom to up
            for (int i = endY; i >= begY; i--) {
                ret.push_back(matrix[i][begX]);
            }
            if (++begX > endX) break;
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
    vector<vector<int>> matrix = { { 1, 2, 3 }, { 4, 5, 6 } };
    vector<vector<int>> matrix2 = { { 2, 3 } };
    vector<vector<int>> matrix3 = { {1,2,3,4,5}, {6,7,8,9,10}, {11,12,13,14,15}, {16,17,18,19,20}, {21,22,23,24,25} };

    vector<int> ret;

    ret = sol.spiralOrder(matrix);
    print_ret(ret);

    ret = sol.spiralOrder(matrix2);
    print_ret(ret);

    ret = sol.spiralOrder(matrix3);
    print_ret(ret);

    return 0;
}
