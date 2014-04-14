/*

 ZigZag Conversion

 The string "PAYPALISHIRING" is written in a zigzag pattern on a given
 number of rows like this: (you may want to display this pattern in a
 fixed font for better legibility)

 P   A   H   N
 A P L S I I G
 Y   I   R

 And then read line by line: "PAHNAPLSIIGYIR"
 Write the code that will take a string and make this conversion given a number of rows:

 string convert(string text, int nRows);
 convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".

 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string convert(string s, int nRows)
    {
        if (nRows <= 0)
            return ""; // invalid

        int len = s.size();
        if (nRows == 1 || len <= 1)
            return s;

        int t = nRows + nRows - 2; // char number of " |/ "
        int nCols = (s.size() / t + 1) * (nRows - 1); // enough to store zigzag
        vector<vector<char>> v(nRows, vector<char>(nCols));

        int row = 0, col = 0;
        bool down = true;
        for (int i = 0; i < len; i++) {
            if (down) { // fill char downward
                v[row][col] = s[i];
                row++;
                if (row == nRows) { // reverse tag
                    row--;
                    down = false;
                }
            } else { // upper right
                row--;
                col++;
                v[row][col] = s[i];
                if (row == 0) { // reverse tag
                    row++;
                    down = true;
                }
            }
        }

        // get output
        string ret;
        for (auto &row : v)
            for (auto t : row)
                if (t)
                    ret += t;

        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    string s("PAYPALISHIRING");

    cout << sol.convert(s, 3) << endl;

    return 0;
}
