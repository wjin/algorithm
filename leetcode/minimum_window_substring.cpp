/*

 Minimum Window Substring

 Given a string S and a string T, find the minimum window in S which will contain
 all the characters in T in complexity O(n).

 For example,
 S = "ADOBECODEBANC"
 T = "ABC"

 Minimum window is "BANC".

 Note:
 If there is no such window in S that covers all characters in T, return the empty string "".

 If there are multiple such windows, you are guaranteed that there will always be only one unique
 minimum window in S.

 */

#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    string minWindow(string S, string T)
    {
        int sLen = S.size(), tLen = T.size();
        if (tLen == 0 || tLen > sLen ) return string(); // invalid

        const int charSet = 256;
        vector<int> need(charSet, 0), cur(charSet, 0);
        int i = 0, j = 0, s = 0, e = INT_MAX;
        int cnt = 0; // count used to verify whether current window is qualified

        for (auto t : T)
            need[t]++; // construct map according to T

        // two pointers advance
        // i is used to track the beginning
        // j is used to find a qualified window
        // O(n)
        for (; j < sLen; j++) {
            cur[S[j]]++;
            if (cur[S[j]] <= need[S[j]]) cnt++;
            if (cnt == tLen) {
                // decrease window if possible
                while (cur[S[i]] > need[S[i]]) {
                    cur[S[i]]--;
                    i++;
                }

                // update answer
                if (j - i < e - s) {
                    s = i;
                    e = j;
                }

                // unqualified window to start next search
                cnt--;
                cur[S[i]]--;
                i++;
            }
        }

        if (e == INT_MAX)
            return string(); // no qualified window
        return S.substr(s, e - s + 1);
    }
};

int main(int argc, char* argv[])
{
    string s("ADOBECODEBANC");
    string t("ABC");

    Solution sol;
    cout << sol.minWindow(s, t) << endl;

    return 0;
}
