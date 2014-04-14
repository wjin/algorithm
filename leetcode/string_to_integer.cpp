/*

 String to Integer (atoi)

 Implement atoi to convert a string to an integer.

 Hint: Carefully consider all possible input cases. If you want a challenge,
 please do not see below and ask yourself what are the possible input cases.

 Notes: It is intended for this problem to be specified vaguely (ie, no given input specs).
 You are responsible to gather all the input requirements up front.

 spoilers alert... click to show requirements for atoi.

 Requirements for atoi:
 The function first discards as many whitespace characters as necessary until the first
 non-whitespace character is found. Then, starting from this character,
 takes an optional initial plus or minus sign followed by as many numerical digits as possible,
 and interprets them as a numerical value.

 The string can contain additional characters after those that form the integral number,
 which are ignored and have no effect on the behavior of this function.

 If the first sequence of non-whitespace characters in str is not a valid integral number,
 or if no such sequence exists because either str is empty or it contains only whitespace characters,
 no conversion is performed.

 If no valid conversion could be performed, a zero value is returned.
 If the correct value is out of the range of representable values, INT_MAX (2147483647)
 or INT_MIN (-2147483648) is returned.

 */

#include <iostream>
#include <climits>
#include <cctype>

using namespace std;

int err = 0;
class Solution
{
public:
    int atoi(const char *str)
    {
        err = 0;
        if (str == nullptr) {
            err = 1;  // invalid input
            return 0;
        }

        bool minus = false;
        long long ret = 0; // long long

        // delete leading whitespace
        while (*str == ' ')
            str++;

        // deal with sign
        if (*str == '-' || *str == '+') {
            minus = (*str == '-' ? true : false);
            str++;
        }

        if (*str == '\0' || !isdigit(*str)) {
            err = 1;  // invalid input
            return 0;
        }

        while (*str != '\0' && isdigit(*str)) {
            ret = ret * 10 + *str - '0';
            str++;

            // deal with overflow carefully
            if ((minus && ret > ((long long) INT_MAX + 1))
                    || (!minus && (ret > INT_MAX))) {
                err = 2; // overflow
                return (minus ? INT_MIN : INT_MAX);
            }
        }

        return (minus ? -ret : ret);
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    const char *s0 = nullptr;
    const char *s1 = "";
    const char *s2 = "  ";
    const char *s3 = "  -";
    const char *s4 = "a123";
    const char *s5 = "  +123";
    const char *s6 = "  -123";
    const char *s7 = "  -+123";
    const char *s8 = "  -+123 ";
    const char *s9 = "  +123a1";
    const char *s10 = "99999999999";
    const char *s11 = "2147483647";
    const char *s12 = "-2147483648";
    const char *s13 = "21474836471";
    const char *s14 = "-21474836481";

    cout << "test s0: " << sol.atoi(s0) << ends;
    cout << err << endl;
    cout << "test s1: " << sol.atoi(s1) << ends;
    cout << err << endl;
    cout << "test s2: " << sol.atoi(s2) << ends;
    cout << err << endl;
    cout << "test s3: " << sol.atoi(s3) << ends;
    cout << err << endl;
    cout << "test s4: " << sol.atoi(s4) << ends;
    cout << err << endl;
    cout << "test s5: " << sol.atoi(s5) << ends;
    cout << err << endl;
    cout << "test s6: " << sol.atoi(s6) << ends;
    cout << err << endl;
    cout << "test s7: " << sol.atoi(s7) << ends;
    cout << err << endl;
    cout << "test s8: " << sol.atoi(s8) << ends;
    cout << err << endl;
    cout << "test s9: " << sol.atoi(s9) << ends;
    cout << err << endl;
    cout << "test s10: " << sol.atoi(s10) << ends;
    cout << err << endl;
    cout << "test s11: " << sol.atoi(s11) << ends;
    cout << err << endl;
    cout << "test s12: " << sol.atoi(s12) << ends;
    cout << err << endl;
    cout << "test s13; " << sol.atoi(s13) << ends;
    cout << err << endl;
    cout << "test s14: " << sol.atoi(s14) << ends;
    cout << err << endl;

    return 0;
}
