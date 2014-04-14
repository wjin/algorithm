/*

   Word Ladder II

   Given two words (start and end), and a dictionary,
   find all shortest transformation sequence(s)
   from start to end, such that:

   Only one letter can be changed at a time
   Each intermediate word must exist in the dictionary
   For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return
[
["hit","hot","dot","dog","cog"],
["hit","hot","lot","log","cog"]
]

Note:
All words have the same length.
All words contain only lowercase alphabetic characters

*/

#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <climits>

using namespace std;

// DFS
// cannot pass OJ, TLE
class Solution
{
public:
    void dfs(vector<vector<string>> &ret, vector<string> &transform, size_t maxLen, string start,
             const string &end, unordered_set<string> &dict, unordered_set<string> &used)
    {
        size_t curLen = transform.size();
        if (curLen > maxLen) return;

        if (start == end) {
            if (ret.empty() || ret[0].size() == curLen) {
                ret.push_back(transform);
            } else if (ret[0].size() > curLen) {
                ret.clear();
                ret.push_back(transform);
            }

            maxLen = curLen; // decrease search depth
            return;
        }

        string t(start);
        for (size_t i = 0; i < end.size(); i++) {
            for (char c = 'a'; c <= 'z'; c++) {
                if (t[i] == c) continue; // itself

                t[i] = c;
                // t is not used and in the dict
                if (used.find(t) == used.end() &&
                        dict.find(t) != dict.end()) {
                    used.insert(t);
                    transform.push_back(t);
                    dfs(ret, transform, maxLen, t, end, dict, used);
                    used.erase(t);
                    transform.pop_back();
                }
            }

            t[i] = start[i]; // reset t to cur
        }
    }


    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict)
    {
        vector<vector<string>> ret;

        size_t len = start.size();
        if (len != end.size() || len == 0 || start == end) return ret; // invalid

        unordered_set<string> used;
        vector<string> transform;
        size_t maxLen = INT_MAX;

        // prepare, be carefull about adding end to dict...
        transform.push_back(start);
        dict.insert(end);

        dfs(ret, transform, maxLen, start, end, dict, used);

        return ret;
    }
};

// BFS
// TLE in the beginning, optimize push queue opreation
// Actually, I pushed duplicate words into the queue
//
// unordered_map<string, unordered_set<string>> &father can be unordered_multimap<string, string>
// gcc 4.8 ran into build error when use equal_range... (fix build error by upgrading gcc to 4.8.2)
//
class Solution2
{
public:
    void getPath(string &start, string &end, unordered_set<string> &dict,
                 unordered_multimap<string, string> &father, vector<vector<string>> &ret, vector<string> &path)
    {
        path.push_back(start);
        if (start == end) {
            ret.push_back(vector<string>(path.rbegin(), path.rend()));
        } else {
            auto range = father.equal_range(start);
            for (auto ite = range.first; ite != range.second; ++ite) {
                getPath(ite->second, end, dict, father, ret, path);
            }
        }
        path.pop_back();
    }

    void bfs(string &start, string &end, unordered_set<string> &dict,
             vector<vector<string>> &ret)
    {
        size_t len = start.size();
        if (len != end.size() || len == 0 || start == end) return; // invalid

        unordered_set<string> used; // avoid duplicate word in the path
        unordered_set<string> levelUsed; // delete the same level duplicate words using set
        unordered_multimap<string, string> father; // use it to get path

        queue<string> q;
        q.push(start);
        int levelSize = 1;
        bool found = false;

        while (!q.empty()) {
            string cur = q.front();
            string t(cur);
            q.pop();
            levelSize--;

            for (size_t i = 0; i < len; i++) {
                for (char c = 'a'; c <= 'z'; c++) {
                    if (t[i] == c) continue; // itself

                    t[i] = c;
                    if (t == end) { // find it
                        found = true;
                        father.insert(make_pair(t, cur));
                        break;
                    }

                    // t is not used and is in the dict
                    if (used.count(t) == 0 && dict.count(t) != 0) {
                        // don't push it to queue, it will push many duplicate elements
                        // just push levelUsed element
                        // q.push(t); // don't push it to queue, it will push many nonused elements
                        levelUsed.insert(t);
                        father.insert(make_pair(t, cur));
                    }
                }
                t[i] = cur[i]; // reset t to cur
            }

            if (levelSize == 0) { // finish one level
                if (found) break;
                for (auto e : levelUsed) {
                    used.insert(e);
                    q.push(e); // insert here
                }
                levelSize = q.size();
                levelUsed.clear();
            }
        }

        if (found) {
            vector<string> path;
            getPath(end, start, dict, father, ret, path);
        }
    }

    vector<vector<string>> findLadders(string &start, string &end, unordered_set<string> &dict)
    {
        vector<vector<string>> ret;
        bfs(start, end, dict, ret);
        return ret;
    }
};

void print_ret(vector<vector<string>> &ret)
{
    for (auto &row : ret) {
        for (auto e : row) {
            cout << e << ' ';
        }
        cout << endl;
    }
}

int main(int argc, char *argv[])
{
    Solution sol;
    Solution2 sol2;

    string start("hit");
    string end("cog");
    unordered_set<string> dict = {"hot","dot","dog","lot","log"};

    // bug
    string start1("red");
    string end1("tax");
    unordered_set<string> dict1 = {"ted","tex","red","tax","tad","den","rex","pee"};

    vector<vector<string>> ret;

    ret = sol.findLadders(start, end, dict);
    print_ret(ret);
    ret = sol2.findLadders(start, end, dict);
    print_ret(ret);

    ret = sol.findLadders(start1, end1, dict1);
    print_ret(ret);
    ret = sol2.findLadders(start1, end1, dict1);
    print_ret(ret);

    return 0;
}
