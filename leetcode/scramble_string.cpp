/*

Scramble String

Given a string s1, we may represent it as a binary tree by partitioning
it to two non-empty substrings recursively.

Below is one possible representation of s1 = "great":

    great
   /    \
  gr    eat
 / \    /  \
g   r  e   at
           / \
          a   t

To scramble the string, we may choose any non-leaf node and swap its two children.

For example, if we choose the node "gr" and swap its two children,
it produces a scrambled string "rgeat".

    rgeat
   /    \
  rg    eat
 / \    /  \
r   g  e   at
           / \
          a   t

We say that "rgeat" is a scrambled string of "great".
Similarly, if we continue to swap the children of nodes "eat" and "at",
it produces a scrambled string "rgtae".

    rgtae
   /    \
  rg    tae
 / \    /  \
r   g  ta  e
       / \
      t   a

We say that "rgtae" is a scrambled string of "great".
Given two strings s1 and s2 of the same length, determine if s2 is a
scrambled string of s1.

*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <map>

using namespace std;

// general search cannot pass OJ
// 1) cache search result
// 2) cut
class Solution
{
    typedef string::iterator ite;
    typedef tuple<ite, ite, ite> Key;
    //unordered_map<Key, bool> cache;
    map<Key, bool> cache;

    bool scramble_cache(ite begin1, ite end1, ite begin2)
    {
        Key t = make_tuple(begin1, end1, begin2);
        if (cache.count(t) != 0) return cache[t];
        cache[t] = scramble(begin1, end1, begin2);
        return cache[t];
    }

    bool scramble(ite begin1, ite end1, ite begin2)
    {
        auto len = distance(begin1, end1);
        auto end2 = next(begin2, len);

        if (len == 1) return *begin1 == *begin2;

        // cut
        // without cut, cannot pass OJ
        int c[26] = { 0 };
        for (int i = 0; i < len; i++) c[*(begin1 + i) - 'a']++;
        for (int i = 0; i < len; i++) c[*(begin2 + i) - 'a']--;
        for (int i = 0; i < 26; i++)
            if (c[i] != 0) return false;

        // recursive search each composition
        for (int i = 1; i < len; i++) {
            if ((scramble_cache(begin1, begin1 + i, begin2) && scramble_cache(begin1 + i, end1, begin2 + i)) ||
                    (scramble_cache(begin1, begin1 + i, end2 - i) && scramble_cache(begin1 + i, end1, begin2)))
                return true;
        }

        return false;
    }

public:
    bool isScramble(string s1, string s2)
    {
        if (s1.size() != s2.size()) return false;
        cache.clear();
        return scramble(s1.begin(), s1.end(), s2.begin());
    }
};

// dp solution from internet
class Solution2
{
public:
    bool isScramble(string s1, string s2)
    {
        const int N = s1.size();
        if (N != s2.size()) return false;

        // f[n][i][j] means whether two strings(length is n), starting from
        // s1[i] and s2[j], are scramble
        // f[n][i][j]} = (f[k][i][j] && f[n-k][i+k][j+k]) || (f[k][i][j+n-k] && f[n-k][i+k][j])
        // k: [1...n)
        bool f[N + 1][N][N];

        // initialization
        fill_n(&f[0][0][0], (N + 1) * N * N, false);
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                f[1][i][j] = s1[i] == s2[j];

        for (int n = 1; n <= N; ++n) {
            for (int i = 0; i + n <= N; ++i) {
                for (int j = 0; j + n <= N; ++j) {
                    for (int k = 1; k < n; ++k) {
                        if ((f[k][i][j] && f[n - k][i + k][j + k]) ||
                                (f[k][i][j + n - k] && f[n - k][i + k][j])) {
                            f[n][i][j] = true;
                            break;
                        }
                    }
                }
            }
        }

        return f[N][0][0];
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    Solution2 sol2;

    string s11("rgeat"), s12("great");
    string s21("rgtae"), s22("great");
    string s31("rgtae"), s32("greaa");
    string s41("ackbdflwqhqarscoepmmxyymcarbjn"), s42("mphoebfamrmcscdblwryqykaaqjcnx");
    string s51("xstjzkfpkggnhjzkpfjoguxvkbuopi"), s52("xbouipkvxugojfpkzjhnggkpfkzjts");

    cout << sol.isScramble(s11, s12) << endl;
    cout << sol.isScramble(s21, s22) << endl;
    cout << sol.isScramble(s31, s32) << endl;
    cout << sol.isScramble(s41, s42) << endl;
    cout << sol.isScramble(s51, s52) << endl;

    cout << sol2.isScramble(s11, s12) << endl;
    cout << sol2.isScramble(s21, s22) << endl;
    cout << sol2.isScramble(s31, s32) << endl;
    cout << sol2.isScramble(s41, s42) << endl;
    cout << sol2.isScramble(s51, s52) << endl;

    return 0;
}
