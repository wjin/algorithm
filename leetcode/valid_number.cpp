/*

   Valid Number

   Validate if a given string is numeric.

   Some examples:
   "0" => true
   " 0.1 " => true
   "abc" => false
   "1 a" => false
   "2e10" => true

Note: It is intended for the problem statement to be ambiguous.
You should gather all requirements up front before implementing one.

*/

#include <iostream>

using namespace std;

// solution from internet
// finite state machine
class Solution
{
    enum InputType {
        INVALID,   // 0
        SPACE,     // 1
        SIGN,      // 2
        DIGIT,     // 3
        DOT,       // 4
        EXPONENT,  // 5
        NUM_INPUTS // 6
    };

public:
    bool isNumber(const char *s)
    {
        if (s == nullptr) return false; // invalid

        // [+/-].xxx : is valid
        // xxx.[x] : is valid
        const int transitionTable[][NUM_INPUTS] = {
            -1, 0, 3, 1, 2, -1,     // state 0: initial state (leading space)
            -1, 8, -1, 1, 4, 5,     // state 1: digit
            -1, -1, -1, 4, -1, -1,  // state 2: dot
            -1, -1, -1, 1, 2, -1,   // state 3: sign
            -1, 8, -1, 4, -1, 5,    // state 4: digit + dot
            -1, -1, 6, 7, -1, -1,   // state 5: digit + exponent
            -1, -1, -1, 7, -1, -1,  // state 6: digit + exponent + sign
            -1, 8, -1, 7, -1, -1,   // state 7: digit + exponent + digit
            -1, 8, -1, -1, -1, -1,  // state 8: ending space
        };

        int state = 0;
        for (; *s != '\0'; ++s) {
            InputType inputType = INVALID;
            if (isspace(*s))
                inputType = SPACE;
            else if (*s == '+' || *s == '-')
                inputType = SIGN;
            else if (isdigit(*s))
                inputType = DIGIT;
            else if (*s == '.')
                inputType = DOT;
            else if (*s == 'e' || *s == 'E')
                inputType = EXPONENT;

            // Get next state from current state and input symbol
            state = transitionTable[state][inputType];

            // Invalid input
            if (state == -1) return false;
        }

        // If the current state belongs to one of the accepting (final) states,
        // then the number is valid
        return state == 1 || state == 4 || state == 7 || state == 8;
    }
};

/// tricky, use API...
class Solution2
{
public:
    bool isNumber (char const* s)
    {
        char* endptr = nullptr;
        strtod(s, &endptr);
        if (endptr == s) return false;
        for (; *endptr; ++endptr)
            if (!isspace (*endptr)) return false;
        return true;
    }
};


int main(int argc, char *argv[])
{
    Solution sol;
    Solution2 sol2;

    const char *s1 = "0";
    const char *s2 = " 0.1 ";
    const char *s3 = "abc";
    const char *s4 = "1 a";
    const char *s5 = "2e10";

    cout << sol.isNumber(s1) << endl;
    cout << sol.isNumber(s2) << endl;
    cout << sol.isNumber(s3) << endl;
    cout << sol.isNumber(s4) << endl;
    cout << sol.isNumber(s5) << endl;

    cout << sol2.isNumber(s1) << endl;
    cout << sol2.isNumber(s2) << endl;
    cout << sol2.isNumber(s3) << endl;
    cout << sol2.isNumber(s4) << endl;
    cout << sol2.isNumber(s5) << endl;

    return 0;
}
