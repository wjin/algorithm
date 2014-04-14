/*

   Spiral Matrix ||

   Given an integer n, generate a square matrix filled with elements
   from 1 to n2 in spiral order.

   For example,
   Given n = 3,

   You should return the following matrix:
   [
   [ 1, 2, 3 ],
   [ 8, 9, 4 ],
   [ 7, 6, 5 ]
   ]

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        if (n <= 0) return vector<vector<int>>(); // invalid
        vector<vector<int>> ret(n, vector<int>(n, 0));

        // don't compare int with size_t as there may be negative number
        int total = n * n;
        int cycle = 0; // not size_t
        int i = 0, j = 0;
        int num = 0;
        while (true) {
            // right
            j = 0; // be careful to start next cycle
            for (j = j + cycle; j < n - cycle; j++) {
                ret[i][j] = ++num;
                if (num == total) return ret;
            }
            j--; // let j valid

            // down
            for (i = cycle + 1; i < n - cycle; i++) {
                ret[i][j] = ++num;
                if (num == total) return ret;
            }
            i--;

            // left
            for (j = n - cycle - 2; j >= cycle; j--) {
                ret[i][j] = ++num;
                if (num == total) return ret;
            }
            j++;

            // up
            for (i = n - cycle - 2; i > cycle; i--) {
                ret[i][j] = ++num;
                if (num == total) return ret;
            }
            i++;

            cycle++;
        }

        return ret;
    }

};

class Solution2
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        if (n <= 0) return vector<vector<int>>(); // invalid
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        int num  = 0;
        int rowStart = 0, rowEnd = matrix.size() - 1;
        int colStart = 0, colEnd = matrix[0].size() - 1;

        while (true) {
            for (int j = colStart; j <= colEnd; j++) {
                matrix[rowStart][j] = ++num;
            }
            if (++rowStart > rowEnd) break;

            for (int i = rowStart; i <= rowEnd; i++) {
                matrix[i][colEnd] = ++num;
            }
            if (--colEnd < colStart) break;

            for (int j = colEnd; j >= colStart; j--) {
                matrix[rowEnd][j] = ++num;
            }
            if (--rowEnd < rowStart) break;

            for (int i = rowEnd; i >= rowStart; i--) {
                matrix[i][colStart] = ++num;
            }
            if (++colStart > colEnd) break;
        }
        return matrix;
    }
};

void print_ret(vector<vector<int>> &ret)
{
    for (auto &row : ret)
        for (auto col : row)
            cout << col << ' ';
    cout << endl;
}

int main(int argc, char *argv[])
{
    Solution sol;
    Solution2 sol2;
    vector<vector<int>> ret;

    ret = sol.generateMatrix(1);
    print_ret(ret);

    ret = sol.generateMatrix(2);
    print_ret(ret);

    ret = sol.generateMatrix(3);
    print_ret(ret);

    ret = sol2.generateMatrix(1);
    print_ret(ret);

    ret = sol2.generateMatrix(2);
    print_ret(ret);

    ret = sol2.generateMatrix(3);
    print_ret(ret);

    return 0;
}
