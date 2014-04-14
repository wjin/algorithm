/*

   Multiply Strings

   Given two numbers represented as strings, return multiplication
   of the numbers as a string.

   Note: The numbers can be arbitrarily large and are non-negative.

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    // transform string to vector array
    // regarding each char as a int in vector, reversely
    vector<int> str_to_vec(string &s)
    {
        vector<int> ret;
        transform(s.rbegin(), s.rend(), back_inserter(ret),
        [] (char c) {
            return c - '0';
        } );
        return ret;
    }

    // transform vector to string
    string vec_to_str(vector<int> &v)
    {
        string ret;

        // find the last non-zero
        auto ite = find_if(v.rbegin(), v.rend(),
        [] (int n) {
            return n > 0;
        } );

        // transform to string
        transform(ite, v.rend(), back_inserter(ret),
        [] (char c) {
            return c + '0';
        } );

        if (ret.empty()) ret += '0'; // result is zero

        return ret;
    }

    // simulate integer multiplication
    vector<int> product(vector<int> &v1, vector<int> &v2)
    {
        int len1 = v1.size();
        int len2 = v2.size();
        vector<int> ret(len1 + len2, 0);

        for (int i = 0; i < len1; i++) {
            for (int j = 0; j < len2; j++) {
                // need to add product to original value first
                ret[i + j] += v1[i] * v2[j];

                ret[i + j + 1] += ret[i + j] / 10; // carry
                ret[i + j] %= 10; // remain
            }
        }

        return ret;
    }

    string multiply(string num1, string num2)
    {
        vector<int> v1 = str_to_vec(num1);
        vector<int> v2 = str_to_vec(num2);
        vector<int> ret = product(v1, v2);
        return vec_to_str(ret);
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    string s11("12345"), s12("10000000000000000000000000000000000");
    string s21("99999"), s22("999");
    string s31("0"), s32("1");
    string s41("1"), s42("2");

    cout << sol.multiply(s11, s12) << endl;
    cout << sol.multiply(s21, s22) << endl;
    cout << sol.multiply(s31, s32) << endl;
    cout << sol.multiply(s41, s42) << endl;

    return 0;
}
