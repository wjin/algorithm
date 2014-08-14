/*

1.5

Implement a method to perform basic string compression using the counts
of repeated characters. For example, the string aabcccccaaa would become
a2blc5a3. If the "compressed" string would not become smaller than the original
string, your method should return the original string.

*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
public:
    string compress(const string &s)
    {
        stringstream ss;

        int i = 0, j = 0, len = s.length();

        for (; i < len; i = j) {
            j = i + 1;
            while (j < len && s[i] == s[j]) j++;

            ss << s[i] << j - i;
        }

        string ret;
        ss >> ret;

        if (ret.length() < len) return ret;

        return s;
    }
};

int main(int argc, const char* argv[])
{
    Solution sol;
    string s("aabcccccaaa");
    string s2("aabc");

    cout << sol.compress(s) << endl;
    cout << sol.compress(s2) << endl;

    return 0;
}
