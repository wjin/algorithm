/*

   Rotate Image

   You are given an n x n 2D matrix representing an image.

   Rotate the image by 90 degrees (clockwise).

   Follow up:
   Could you do this in-place?

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int len = matrix.size();
        if (len <= 1) return;

        // swap counter-diagonal
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < len - i; j++) {
                swap(matrix[i][j], matrix[len - 1 - j][len - 1 - i]);
            }
        }

        // swap horizontal middle line
        for (int i = 0; i < len / 2; i++) {
            for (int j = 0; j < len; j++) {
                swap(matrix[i][j], matrix[len - 1 - i][j]);
            }
        }
    }
};

class Solution2
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int len = matrix.size();
        if (len <= 1) return;

        // swap element layer by layer (circle by circle)
        // from outside to inside
        for (int layer = 0; layer < len / 2; layer++) {
            int first = layer, last = len - 1 - layer;

            // traverse row
            for (int i = first; i < last; i++) {
                int offset = i - first; // offset to the start

                int top = matrix[first][i]; // store top element

                // left to top
                matrix[first][i] = matrix[last - offset][first];

                // bottom to left
                matrix[last - offset][first] = matrix[last][last - offset];

                // right to bottom
                matrix[last][last - offset] = matrix[i][last];

                // top to right
                matrix[i][last] = top;
            }
        }
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<vector<int>> v = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    sol.rotate(v);

    for (auto &row : v) {
        for (auto c : row) {
            cout << c << ends;
        }
        cout << endl;
    }

    return 0;
}
