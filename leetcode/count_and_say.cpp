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

using namespace std;

class Solution
{
public:
    string getNext(string &s)
    {
        string ret;
        int cnt = 1;

        int i;
        for (i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) // count duplicate numbers
                cnt++;
            else { //
                ret += cnt + '0'; // count
                ret += s[i - 1]; // number
                cnt = 1; // reset count
            }
        }

        // the last one
        ret += cnt + '0';
        ret += s[i - 1];

        return ret;
    }

    string countAndSay(int n)
    {
        if (n <= 0)
            return "";

        string ret("1");
        if (n == 1)
            return ret;

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
