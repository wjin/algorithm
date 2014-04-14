/*

 Letter Combinations of a Phone Number

 Given a digit string, return all possible letter combinations that the number could represent.
 A mapping of digit to letters (just like on the telephone buttons) is given below.


 Input:Digit string "23"
 Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 Note:
 Although the above answer is in lexicographical order, your answer could be in any order you want.

 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
private:
    vector<string> d2c; // digit to char map
public:
    Solution() :
        d2c( { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv",
        "wxyz"
    })
    {
    }

    vector<string> letterCombinations(string digits)
    {
        int len = digits.size();
        vector<string> ret;

        dfs(digits, ret, "", 0, len);

        return ret;
    }

    void dfs(string &digits, vector<string> &ret, string s, int start, // s, not &s
             int end)
    {
        if (start == end) {
            ret.push_back(s);
        } else {
            int index = digits[start] - '0';
            for (int i = 0; i < d2c[index].size(); i++)
                dfs(digits, ret, s + d2c[index][i], start + 1, end);
        }
    }
};

// iterative
class Solution2
{
    // static vector<string> d2c;
    const vector<string> d2c {
        "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv",
        "wxyz"
    };

public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> ret(1); // one initial empty string

        for (auto d : digits) {
            int n = ret.size();
            int m = d2c[d - '0'].size();

            ret.resize(n * m);
            // add n * (m - 1) duplicate elements
            // there are n * m elements in total
            for (int i = 1; i < m; i++) {
                copy(ret.begin(), ret.begin() + n, ret.begin() + n * i);
            }

            // for each duplicate group (m groups in total)
            // add one more character to each group with different character
            for (int i = 0; i < m ; i++) {
                for_each(ret.begin() + n * i, ret.begin() + n * (i + 1), [&](string &s) {
                    s += d2c[d - '0'][i];
                });
            }
        }

        return ret;
    }
};
#if 0
vector<string> Solution2::d2c = {
    "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv",
    "wxyz"
};
#endif

int main(int argc, char *argv[])
{
    Solution sol;
    Solution2 sol2;
    string s("23");

    vector<string> ret = sol.letterCombinations(s);
    for (auto t : ret)
        cout << t << ' ' ;
    cout << endl;

    ret = sol2.letterCombinations(s);
    for (auto t : ret)
        cout << t << ' ' ;
    cout << endl;

    return 0;
}
