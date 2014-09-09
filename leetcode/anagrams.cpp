/*

 Anagrams

 Given an array of strings, return all groups of strings that are anagrams.

 Note: All inputs will be in lower-case.

 */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<string> anagrams(vector<string> &strs)
    {
        vector<string> ret;
        vector<string> sorted;

        if (strs.empty())
            return ret;

        unordered_multiset<string> hash;
        // sort each string and then insert it to hash table
        // also backup sorted string
        for (auto str : strs) {
            string t(str);
            sort(t.begin(), t.end());
            sorted.push_back(t);
            hash.insert(t);
        }

        for (int i = 0; i < sorted.size(); i++) {
            if (hash.count(sorted[i]) > 1)
                ret.push_back(strs[i]);
        }

        return ret;
    }
};

class Solution2
{
public:
    vector<string> anagrams(vector<string> &strs)
    {
        vector<string> ret;

        if (strs.empty())
            return ret;

        unordered_map<string, string> m;
        unordered_set<string> added;

        for (auto str : strs) {
            string t(str);
            sort(t.begin(), t.end());

            if (!m.count(t)) {
                m[t] = str;
            } else {
                ret.push_back(str); // add str

                // add previous one
                if (!added.count(m[t])) {
                    added.insert(m[t]);
                    ret.push_back(m[t]);
                }
            }
        }
        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<string> strs = { "cat", "act", "dog", "god", "abc", "xyz" };

    vector<string> ret = sol.anagrams(strs);

    for (auto t : ret)
        cout << t << endl;
    return 0;

}
