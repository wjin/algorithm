/*

 Valid Parentheses

 Given a string containing just the characters '(', ')', '{', '}', '[' and ']',
 determine if the input string is valid.

 The brackets must close in the correct order, "()" and "()[]{}" are
 all valid but "(]" and "([)]" are not.

 */

#include <iostream>
#include <stack>
#include <map>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stk;
        map<char, char> m;
        m[')'] = '(';
        m[']'] = '[';
        m['}'] = '{';

        int i = 0;
        for (; i < s.size(); i++) {
            char c = s[i];
            if (c == '(' || c == '[' || c == '{') {
                stk.push(c);
            } else {
                if (!stk.empty() && stk.top() == m[c]) {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }

        return (stk.empty() && i == s.size()) ? true : false;
    }
};

int main(int argc, char *argv[])
{
    string s1("()[]{}");
    string s2("([)]");
    Solution sol;

    cout << sol.isValid(s1) << endl;
    cout << sol.isValid(s2) << endl;

    return 0;
}
