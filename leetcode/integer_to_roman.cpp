/*

 Integer to Roman

 Given an integer, convert it to a roman numeral.

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
    string intToRoman(int num)
    {
        const int radix[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4,
                              1
                            };
        const string symbol[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL",
                                  "X", "IX", "V", "IV", "I"
                                };

        string ret;
        for (int i = 0; num > 0; ++i) {
            int cnt = num / radix[i];
            num %= radix[i];
            while (cnt--)
                ret += symbol[i];
        }

        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    cout << sol.intToRoman(1) << endl;
    cout << sol.intToRoman(4) << endl;
    cout << sol.intToRoman(5) << endl;
    cout << sol.intToRoman(9) << endl;
    cout << sol.intToRoman(10) << endl;
    cout << sol.intToRoman(11) << endl;
    cout << sol.intToRoman(111) << endl;
    cout << sol.intToRoman(234) << endl;
    cout << sol.intToRoman(2111) << endl;

    return 0;
}
