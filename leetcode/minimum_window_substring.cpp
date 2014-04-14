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
#include <climits>

using namespace std;

class Solution
{
public:
    string minWindow(string S, string T)
    {
        const int charSet = 256;
        int need[charSet] = { 0 };
        int found[charSet] = { 0 };
        int min_len = INT_MAX, min_start = 0;
        int cnt = 0; // count used to verify whether current window is qualified

        if (S.empty() || T.empty())
            return ""; // null

        for (auto t : T)
            need[t]++; // construct map according to T

        // two pointers advance
        // i is used to track the beginning
        // j is used to find a qualified window
        // O(n)
        for (int i = 0, j = 0; j < S.size(); j++) {
            if (need[S[j]] != 0) {
                found[S[j]]++;
                if (found[S[j]] <= need[S[j]])
                    cnt++; // we can also calculate duplicate char in T
            }

            if (cnt == T.size()) { // get one qualified window
                //decrease window as much as possible
                while (need[S[i]] == 0 || found[S[i]] > need[S[i]]) { // bug: need[S[i]] == 0
                    if (found[S[i]] > need[S[i]])
                        found[S[i]]--;
                    i++;
                }

                // update window if possible
                int tmp = j - i + 1;
                if (tmp < min_len) {
                    min_len = tmp;
                    min_start = i;
                }

                // unqualified window to start next search
                cnt--;
                found[S[i]]--;
                i++;
            }
        }

        if (min_len == INT_MAX)
            return ""; // no qualified window
        return S.substr(min_start, min_len);
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
