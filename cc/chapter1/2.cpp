/*

1.2

Implement a function void reverse(char* str) in C or C++ which reverses a nullterminated
string.

*/

#include <iostream>

using namespace std;

class Solution
{
public:
    char * reverseStr(char *s)
    {
        if (s == nullptr) return nullptr;

        char *l = s, *h = s + strlen(s) - 1;

        while (l < h) {
            swap(*l++, *h--);
        }

        return s;
    }
};

int main(int argc, const char* argv[])
{
    Solution sol;

    char s[] = "ab cd"; //char *s = "abcd"; wrong

    cout << s << endl;
    cout << sol.reverseStr(s) << endl;

    return 0;
}
