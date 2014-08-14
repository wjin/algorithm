/*

1.1

Implement an algorithm to determine if a string has all unique characters.
What if you cannot use additional data structures?

*/

#include <iostream>
#include <string>
#include <bitset>

using namespace std;


class Solution
{
public:
    bool isUnique(string s)
    {
        bitset<CHAR_MAX> cs(0); // char set

        for (char c : s) {
            if (cs[c] == 1) return false;
            cs[c] = 1;
        }

        return true;
    }
};

int main(int argc, const char* argv[])
{
    Solution sol;
    string s("abcd");

    cout << sol.isUnique(s) << endl;

    return 0;
}
