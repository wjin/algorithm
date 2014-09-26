/*

Substring with Concatenation of All Words

You are given a string, S, and a list of words, L, that are all of the same length.
Find all starting indices of substring(s) in S that is a concatenation of each word
in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// brute force, slow but clean
// O(n*l*w) time and O(l*w) space
// still can pass OJ
class Solution
{
public:
    vector<int> findSubstring(string S, vector<string> &L)
    {
        vector<int> ret;
        int wCnt = L.size();
        if (wCnt == 0) return ret; // no word
        int wLen = L[0].size(); // same length
        int sLen = S.size();

        unordered_map<string, int> need, cur;

        // store all words and its count to map
        // because there may exist duplicate word
        for (auto w : L)
            need[w]++;

        // traverse S from beginning and verify
        int j = 0;
        for (int i = 0; i <= sLen - wLen * wCnt; i++) {
            cur.clear();

            // verify each word
            for (j = 0; j < wCnt; j++) {
                string word = S.substr(i + j * wLen, wLen);

                // not match
                if (!need.count(word) || cur[word] == need[word]) break;

                cur[word]++;
            }

            if (j == wCnt) ret.push_back(i);
        }

        return ret;
    }
};

// O(n*w) time and O(l*w) space
class Solution2
{
public:
    vector<int> findSubstring(string S, vector<string> &L)
    {
        vector<int> ret;
        int wCnt = L.size();
        if (wCnt == 0) return ret; // no word
        int wLen = L[0].size(); // same length
        int sLen = S.size();

        unordered_map<string, int> need, cur;

        for (auto w : L) {
            need[w]++;
        }

        string word, t;
        int curCnt = 0;
        int start = 0;

        for (int k = 0; k < wLen; k++) {
            curCnt = 0;
            start = k;

            for (int i = k; i < sLen; i += wLen) {
                word = S.substr(i, wLen);

                if (!need.count(word)) {
                    // word not exist, reset
                    cur.clear();
                    curCnt =  0;
                    start = i + wLen;
                } else if (cur[word] < need[word]) {
                    // word exist and valid
                    cur[word]++;
                    curCnt++;
                } else {
                    // word exist but beyond duplicate times

                    // advance start postion until this word
                    t = S.substr(start, wLen);
                    while(t != word) {
                        cur[t]--;
                        curCnt--;
                        start += wLen;
                        t = S.substr(start, wLen);
                    }

                    // skip this `word` to make `its duplicate` valid
                    start += wLen;
                }

                // get one answer
                if (curCnt == wCnt) {
                    ret.push_back(start);
                    t = S.substr(start, wLen);
                    cur[t]--;
                    curCnt--;
                    start += wLen;
                }
            }

            cur.clear();
        }

        return ret ;
    }
};

int main(int argc, char *argv[])
{
    Solution2 sol;

    string S("barfoothefoobarman");
    vector<string> L = { "foo", "bar" };

    vector<int> ret = sol.findSubstring(S, L);

    for (auto e : ret) {
        cout << e << endl;
    }

    return 0;
}
