/*

 Longest Common Prefix

 Write a function to find the longest common prefix string amongst an array of strings.

 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    // divide and conquer
    // does not decrease compare times?
    int judge_prefix(vector<string> &strs, int start, int end)
    {
        if (start == end)
            return strs[start].size();
        else if (start == end - 1) {
            int comLen = 0;
            int minSize = min(strs[start].size(), strs[end].size());
            while (comLen < minSize && strs[start][comLen] == strs[end][comLen])
                comLen++;
            return comLen;
        } else {
            int middle = start + (end - start) / 2;
            int lComLen = judge_prefix(strs, start, middle);
            int rComLen = judge_prefix(strs, middle, end);
            return min(lComLen, rComLen);
#if 0
            int rComLen = judge_prefix(strs, middle + 1, end);
            int len = 0;
            int minLen = min(lComLen, rComLen);
            while (len < minLen && strs[start][len] == strs[end][len])
                len++;

            return len;
#endif
        }
    }

    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.size() == 0)
            return "";
        else if (strs.size() == 1)
            return strs[0];

        int len = judge_prefix(strs, 0, strs.size() - 1);
        return len ? strs[0].substr(0, len) : "";
    }

    string longestCommonPrefix2(vector<string> &strs)
    {
        if (strs.size() == 0) return "";
        for (size_t idx = 0; idx < strs[0].size(); ++idx) {
            for (size_t i = 1; i < strs.size(); ++i) {
                if (strs[i][idx] != strs[0][idx]) return strs[0].substr(0,idx);
            }
        }
        return strs[0];
    }

};

int main(int argc, char *argv[])
{
    vector<string> strs = { "abc", "abc", "abc", "abca" };
    Solution sol;

    cout << sol.longestCommonPrefix(strs) << endl;
    cout << sol.longestCommonPrefix2(strs) << endl;
    return 0;
}
