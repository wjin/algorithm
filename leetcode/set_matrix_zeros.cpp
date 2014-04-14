/*

 Set Matrix Zeroes

 Given a m x n matrix, if an element is 0, set its entire row
 and column to 0.

 Do it in place.

 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    void setZeroes(vector<vector<int> > &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        vector<bool> row_tag(row);
        vector<bool> col_tag(col);

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (matrix[i][j] == 0) {
                    row_tag[i] = true;
                    col_tag[j] = true;
                }

        for (int i = 0; i < row; i++)
            for (int j = 0; j < col; j++)
                if (row_tag[i] || col_tag[j]) {
                    matrix[i][j] = 0;
                }
    }

    // do it in place
    void setZeroes2(vector<vector<int> > &matrix)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        // first row and col tag
        bool row0 = false, col0 = false;

        // record first row 0
        for (int j = 0; j < col && !row0; j++)
            if (!matrix[0][j])
                row0 = true;

        // record first col 0
        for (int i = 0; i < row && !col0; i++)
            if (!matrix[i][0])
                col0 = true;

        // map 0 to first row and col
        for (int i = 1; i < row; i++)
            for (int j = 1; j < col; j++)
                if (matrix[i][j] == 0) {
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }

        // set zero
        for (int i = 1; i < row; i++)
            for (int j = 1; j < col; j++)
                if (!matrix[0][j] || !matrix[i][0]) {
                    matrix[i][j] = 0;
                }

        // set first row
        if (row0) {
            for (int j = 0; j < col; j++)
                matrix[0][j] = 0;
        }

        // set first col
        if (col0) {
            for (int i = 0; i < row; i++)
                matrix[i][0] = 0;
        }
    }
};

void print_matrix(vector<vector<int> > &matrix)
{
    for (auto &row : matrix) {
        for (auto c : row)
            cout << c << ' ';
        cout << endl;
    }
}

int main(int argc, char *argv[])
{
    vector<vector<int>> matrix = { { 1, 1, 1 }, { 2, 0, 2 }, { 3, 3, 3 } };
    Solution sol;

    print_matrix(matrix);
    sol.setZeroes2(matrix);
    print_matrix(matrix);

    return 0;
}
