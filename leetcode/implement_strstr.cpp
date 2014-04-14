/*

 Implement strStr()

 Returns a pointer to the first occurrence of needle in haystack,
 or null if needle is not part of haystack.

 */

#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

// brute force
// TLE
class Solution
{
public:
    char *strStr(char *haystack, char *needle)
    {
        if (haystack == nullptr || needle == nullptr)
            return nullptr;

        int cnt = strlen(haystack) - strlen(needle) + 1;
        if (cnt <= 0)
            return nullptr;

        char *s = haystack;
        char *ts = s, *p = needle;

        while (*ts && cnt--) {
            while (*ts && *p && *ts == *p) {
                ts++;
                p++;
            }

            if (!*p) // got it
                return s;

            s++; // restart next search position
            ts = s;
            p = needle;
        }

        return nullptr;
    }
};

// KMP
class Solution2
{
private:
    vector<int> nextValue;  // next value

    void genNext(char* pattern)
    {
        int pLen = strlen(pattern); // pattern length

        nextValue.push_back(-1); // tag the first element, next[0] = -1
        int j = nextValue[0]; // j is used to get next[k]

        for (int i = 1; i < pLen; i++) {
            while (j > -1 && pattern[j + 1] != pattern[i])
                j = nextValue[j];

            if (pattern[i] == pattern[j + 1])
                j++;

            nextValue.push_back(j);
        }
    }

public:
    char *strStr(char *haystack, char *needle)
    {
        if (haystack == nullptr || needle == nullptr)
            return nullptr;

        size_t sLen = strlen(haystack), pLen = strlen(needle);
        if (sLen < pLen)
            return nullptr;

        if (pLen == 0)
            return haystack;

        // generate next info for needle
        nextValue.clear(); // OJ will reuse this array...
        genNext(needle);

        int j = nextValue[0];
        for (int i = 0; i < sLen; i++) {
            while (j > -1 && needle[j + 1] != haystack[i])
                j = nextValue[j];

            if (haystack[i] == needle[j + 1])
                j++;

            if (j == pLen - 1) {
                return haystack + i - j;
            }
        }

        return nullptr;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    Solution2 sol2;

    char *s1 = "abcdef", *p1 = "bcd";
    char *s2 = "abcdef", *p2 = "bca";
    char *s3 = "abcdef", *p3 = "abcdef";
    char *s4 = "", *p4 = ""; // bug
    char *s5 = "a", *p5 = ""; // bug
    char *s6 = "babbbbbabb", *p6 = "bbab";

    char *p = nullptr;

    cout << sol.strStr(s1, p1) << endl;
    p = sol.strStr(s2, p2);
    cout << (p ? p : "NULLPTR") << endl;
    cout << sol.strStr(s3, p3) << endl;
    //cout << sol.strStr(s4, p4) << endl;
    cout << sol.strStr(s5, p5) << endl;
    cout << sol.strStr(s6, p6) << endl;

    p = nullptr;
    cout << sol2.strStr(s1, p1) << endl;
    p = sol2.strStr(s2, p2);
    cout << (p ? p : "NULLPTR") << endl;
    cout << sol2.strStr(s3, p3) << endl;
    //cout << sol2.strStr(s4, p4) << endl;
    cout << sol2.strStr(s5, p5) << endl;
    cout << sol2.strStr(s6, p6) << endl;

    return 0;
}
