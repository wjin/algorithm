/*

 Count and Say

 The count-and-say sequence is the sequence of integers beginning as follows:
 1, 11, 21, 1211, 111221, ...

 1 is read off as "one 1" or 11.
 11 is read off as "two 1s" or 21.
 21 is read off as "one 2, then one 1" or 1211.
 Given an integer n, generate the nth sequence.

 Note: The sequence of integers will be represented as a string.

 */

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
    string getNext(const string &s)
    {
        stringstream ss;
        int len = s.size();
        int i, j;

        for (i = 0; i < len; ) {
            j = i + 1;
            while (j < len && s[i] == s[j]) j++;

            ss << j - i << s[i];
            i = j;
        }

        return ss.str();
    }

public:
    string countAndSay(int n)
    {
        if (n <= 0)
            return "";

        string ret("1");

        for (int i = 1; i < n; i++) {
            ret = getNext(ret);
        }

        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    cout << sol.countAndSay(1) << endl;
    cout << sol.countAndSay(2) << endl;
    cout << sol.countAndSay(3) << endl;
    cout << sol.countAndSay(4) << endl;
    cout << sol.countAndSay(5) << endl;
    cout << sol.countAndSay(6) << endl;

    return 0;
}
