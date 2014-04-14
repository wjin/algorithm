/*

 Add Binary

 Given two binary strings, return their sum (also a binary string).

 For example,
 a = "11"
 b = "1"
 Return "100".

 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    void charAdd(char c1, char c2, char &carry, char &sum)
    {
        int a = c1 - '0';
        int b = c2 - '0';
        int c = carry - '0';

        sum = (a + b + c) % 2 + '0';
        carry = (a + b + c) / 2 + '0';
    }

    string addBinary(string a, string b)
    {
        if (a.empty())
            return b;
        if (b.empty())
            return a;

        int aLen = a.size(), bLen = b.size();
        string ret;
        char sum = '0';
        char carry = '0';

        while (aLen && bLen) {
            charAdd(a[aLen - 1], b[bLen - 1], carry, sum);
            ret = sum + ret;
            aLen--;
            bLen--;
        }

        while (aLen) {
            charAdd(a[aLen - 1], '0', carry, sum);
            ret = sum + ret;
            aLen--;
        }

        while (bLen) {
            charAdd(b[bLen - 1], '0', carry, sum);
            ret = sum + ret;
            bLen--;
        }

        if (carry == '1')
            ret = '1' + ret;

        return ret;
    }
};

class Solution2
{
public:
    string addBinary(string a, string b)
    {
        vector<char> v;
        int carry = 0;
        int aLen = a.size(), bLen = b.size();

        while (aLen || bLen || carry) {
            int va = (aLen ? a[--aLen] - '0' : 0);
            int vb = (bLen ? b[--bLen] - '0' : 0);
            v.push_back((va + vb + carry) % 2 + '0');
            carry = (va + vb + carry) / 2;
        }

        return string(v.rbegin(), v.rend());
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    Solution2 sol2;
    string s1("11");
    string s2("10");

    string s3;
    string s4("1010");

    cout << sol.addBinary(s1, s2) << endl;
    cout << sol2.addBinary(s1, s2) << endl;

    cout << sol.addBinary(s3, s4) << endl;
    cout << sol2.addBinary(s3, s4) << endl;

    return 0;
}
