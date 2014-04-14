/*

 Search a 2D Matrix

 Write an efficient algorithm that searches for a value in an m x n matrix.
 This matrix has the following properties:

 Integers in each row are sorted from left to right.
 The first integer of each row is greater than the last integer of the previous row.
 For example,

 Consider the following matrix:

 [
 [1,   3,  5,  7],
 [10, 11, 16, 20],
 [23, 30, 34, 50]
 ]

 Given target = 3, return true.

 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    // O(m + n)
    bool searchMatrix(vector<vector<int> > &matrix, int target)
    {
        int row = matrix.size() - 1;
        int col = matrix[0].size() - 1;

        int i = 0, j = col;
        while (i <= row && j >= 0) {
            if (matrix[i][j] == target)
                return true;
            else if (matrix[i][j] < target)
                i++;
            else
                j--;
        }

        return false;
    }

    // binary search O(logm*n)
    bool searchMatrix2(vector<vector<int> > &matrix, int target)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        int low = 0;
        int high = row * col - 1;

        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            int val = matrix[mid / col][mid % col];

            if (val == target) return true;
            else if (val < target) low = mid + 1;
            else high = mid - 1;
        }

        return false;
    }
};

int main(int argc, char *argv[])
{
    vector<vector<int>> v = { { 1, 3, 5, 7 }, { 10, 11, 16, 20 },
        { 23, 30, 34, 50 }
    };
    Solution sol;

    cout << sol.searchMatrix(v, 3) << endl;
    cout << sol.searchMatrix2(v, 3) << endl;

    return 0;
}
