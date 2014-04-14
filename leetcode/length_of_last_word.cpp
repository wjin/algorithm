/*

 Length of Last Word

 Given a string s consists of upper/lower-case alphabets and empty space characters ' ',
 return the length of last word in the string.

 If the last word does not exist, return 0.

 Note: A word is defined as a character sequence consists of non-space characters only.

 For example,
 Given s = "Hello World",
 return 5.

 */

#include <iostream>
#include <cstring>

using namespace std;

class Solution
{
public:
    int lengthOfLastWord(const char *s)
    {
        if (s == NULL)
            return 0;

        int len = strlen(s) - 1;
        int last_word_len = 0;

        while (len >= 0 && s[len] == ' ')
            len--;

        while (len >= 0) {
            if (s[len] == ' ')
                return last_word_len;
            len--;
            last_word_len++;
        }

        return last_word_len;
    }
};

int main(int argc, char *argv[])
{
    const char *s = "Hello World";
    Solution sol;

    cout << sol.lengthOfLastWord(s) << endl;

    return 0;
}
