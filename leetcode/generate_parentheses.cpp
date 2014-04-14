/*

 Generate Parentheses

 Given n pairs of parentheses, write a function to generate all combinations
 of well-formed parentheses.

 For example, given n = 3, a solution set is:

 "((()))", "(()())", "(())()", "()(())", "()()()"

 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    void dfs(vector<string> &ret, string s, int left, int right)
    {
        if (left == 0 && right == 0) {
            ret.push_back(s);
            return;
        }

        if (left > 0) {
            dfs(ret, s + '(', left - 1, right);
        }

        if (right > left) {
            dfs(ret, s + ')', left, right - 1);
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> ret;
        dfs(ret, "", n, n);
        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    vector<string> ret = sol.generateParenthesis(3);

    for (auto t : ret)
        cout << t << endl;

    return 0;
}
