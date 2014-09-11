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
private:
    int cal(const string &s, int n1, int n2)
    {
        if (s == "+") return n1 + n2;
        else if (s == "-") return n1 - n2;
        else if (s == "*") return n1 * n2;
        else return n1 / n2;
    }

    bool isOperator(const string &s)
    {
        return s.size() == 1 && (string("+-*/").find(s) != string::npos);
    }

public:
    int evalRPN(vector<string> &tokens)
    {
        vector<int> v;
        int first, second;

        for (auto e : tokens) {
            if (!isOperator(e)) {
                v.push_back(stoi(e));
            } else {
                second = v.back();
                v.pop_back();
                first = v.back();
                v.pop_back();

                v.push_back(cal(e, first, second));
            }
        }
        return v[0];
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
