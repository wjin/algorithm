/*

 Roman to Integer

 Given a roman numeral, convert it to an integer.

 Input is guaranteed to be within the range from 1 to 3999.

 */

#include <iostream>
#include <string>

using namespace std;

/*

 Roman Numerals, as used today, are based on seven symbols:
 Symbol	Value
 I	1
 V	5
 X	10
 L	50
 C	100
 D	500
 M	1,000

 Numbers are formed by combining symbols together and adding the values.
 So II is two ones, i.e. 2, and XIII is a ten and three ones, i.e. 13.

 There is no zero in this system, so 207, for example, is CCVII,
 using the symbols for two hundreds, a five and two ones.

 1066 is MLXVI, one thousand, fifty and ten, a five and a one.

 Symbols are placed from left to right in order of value, starting with the largest.

 However, in a few specific cases, to avoid four characters being repeated in succession (such as IIII or XXXX)
 these can be reduced using subtractive notation as follows:

 the numeral I can be placed before V and X to make 4 units (IV) and 9 units (IX) respectively
 X can be placed before L and C to make 40 (XL) and 90 (XC) respectively
 C can be placed before D and M to make 400 (CD) and 900 (CM) according to the same pattern.

 */

class Solution
{
public:
    int symbolToInt(const char c)
    {
        switch (c) {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default: // error
            return -1;
        }
    }

    int romanToInt(string s)
    {
        int ret = 0;
        ret += symbolToInt(s[0]); // first symbol

        for (size_t i = 1; i < s.size(); ++i) {
            if (symbolToInt(s[i]) <= symbolToInt(s[i - 1])) { // =
                ret += symbolToInt(s[i]);
            } else {
                // 2 means we need to subtract the previous one
                // which has already been added to ret
                ret += symbolToInt(s[i]) - 2 * symbolToInt(s[i - 1]);
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    cout << sol.romanToInt("I") << endl;
    cout << sol.romanToInt("II") << endl;
    cout << sol.romanToInt("IV") << endl;
    cout << sol.romanToInt("VI") << endl;
    cout << sol.romanToInt("XIX") << endl;
    cout << sol.romanToInt("CXIX") << endl;
    cout << sol.romanToInt("DCCXIX") << endl;
    cout << sol.romanToInt("MMDCCXIX") << endl;

    return 0;
}
