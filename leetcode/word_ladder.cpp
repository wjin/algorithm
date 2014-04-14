/*

Word Ladder

Given two words (start and end), and a dictionary,
find the length of shortest transformation sequence
from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.

*/

#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>

using namespace std;

// can pass OJ, but use 1440 ms
class Solution
{
public:
    int ladderLength(string start, string end, unordered_set<string> &dict)
    {
        size_t len = start.size();
        if (len != end.size() || len == 0 || start == end) return -1; // invalid

        unordered_set<string> used;
        queue<string> q;
        q.push(start);
        int level = 1;
        int levelSize = 0;

        // BFS
        while (!q.empty()) {
            if (levelSize == 0) {
                levelSize = q.size();
                level++;
            }

            string cur = q.front();
            string t(cur);
            q.pop();
            levelSize--;

            for (size_t i = 0; i < len; i++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    if (t[i] == c) continue; // itself

                    t[i] = c;
                    if (t == end) return level; // find it
                    // t is not used and in the dict
                    if (used.find(t) == used.end() &&
                            dict.find(t) != dict.end()) {
                        q.push(t);
                        used.insert(t);
                    }
                }
                t[i] = cur[i]; // reset t to cur
            }
        }

        return 0;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    string start("hit");
    string end("cog");
    unordered_set<string> dict = {"hot","dot","dog","lot","log"};

    cout << sol.ladderLength(start, end, dict) << endl;

    return 0;
}
