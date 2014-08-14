/*

1.8

Assume you have a method isSubstring which checks if one word is a
substring of another. Given two strings, si and s2, write code to check if s2 is
a rotation of si using only one call to isSubstring (e.g.,"waterbottle"is a rotation
of "erbottlewat").

*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution
{
private:
    bool isSubstring(const string &s1, const string &s2)
    {
        return s1.find(s2) != string::npos;
    }
public:
    bool isRotate(const string &s1, const string &s2)
    {
        if (s1.length() != s2.length()) return false;

        return isSubstring(s1 + s1, s2);
    }
};

int main(int argc, const char* argv[])
{
    Solution sol;
    string s1("abc");
    string s2("cab");
    string s3("acb");

    cout << sol.isRotate(s1, s2) << endl;
    cout << sol.isRotate(s1, s3) << endl;

    return 0;
}
