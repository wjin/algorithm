/*

   Evaluate Reverse Polish Notation

   Evaluate the value of an arithmetic expression in Reverse Polish Notation.

   Valid operators are +, -, *, /.
   Each operand may be an integer or another expression.

   Some examples:
   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    int cal(string &s, int n1, int n2)
    {
        char ch = s[0];
        switch (ch) {
        case '+':
            return n1 + n2;
        case '-':
            return n1 - n2;
        case '*':
            return n1 * n2;
        case '/':
            return n1 / n2;
        default:
            return -1; // invalid arithmetic
        };
    }

    bool isNum(string &s, int &ret)
    {
        // consider s is not empty and valid here
        // do not consider overflow

        if (s == "+" || s == "-" || s == "*" || s == "/") return false;

        // may not need
        int sign = 1;
        size_t i = 0;
        if (s[0] == '+') i++;
        if (s[0] == '-') {
            i++;
            sign = -1;
        }

        // could use stoi to convert string to integer
        ret = 0;
        while (i < s.size()) {
            ret = ret * 10 +  s[i] - '0';
            i++;
        }

        ret *= sign;

        return true;
    }

    int evalRPN(vector<string> &tokens)
    {
        vector<int> num;

        int ret = 0;
        for (auto e : tokens) {
            if (isNum(e, ret)) num.push_back(ret);
            else {
                int n2 = num.back();
                num.pop_back();
                int n1 = num.back();
                num.pop_back();
                num.push_back(cal(e, n1, n2));
            }
        }
        return num[0];
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    vector<string> v1 = {"2", "1", "+", "3", "*"}; // 9
    vector<string> v2 = {"4", "13", "5", "/", "+"}; // 6

    cout << sol.evalRPN(v1) << endl;
    cout << sol.evalRPN(v2) << endl;

    return 0;

}
