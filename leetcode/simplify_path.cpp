/*

   Simplify Path

   Given an absolute path for a file (Unix-style), simplify it.

   For example,
   path = "/home/", => "/home"
   path = "/a/./b/../../c/", => "/c"
   click to show corner cases.

   Corner Cases:
   Did you consider the case where path = "/../"?
   In this case, you should return "/".
   Another corner case is the path might contain multiple slashes '/'together,
   such as "/home//foo/". In this case, you should ignore redundant slashes
   and return "/home/foo".

*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        int len = path.size();
        if (len == 0) return "";

        vector<string> dirs;
        for (auto ite = path.begin(); ite != path.end();) {
            ++ite; // skip leading '/'

            // get path end
            auto  pend = find(ite, path.end(), '/');
            string dir(ite, pend);

            // dir might be empty : ///
            // if dir is empty or one dot, ignore...
            if (!dir.empty() && dir != ".") {
                if (dir == "..") {
                    if (!dirs.empty()) dirs.pop_back();
                } else {
                    dirs.push_back(dir); // add dir
                }
            }

            ite = pend;
        }

        string ret;
        for (auto e : dirs) {
            ret += '/';
            ret += e;
        }
        if (ret.empty()) ret = '/';

        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    string s1("/home/");
    string s2("/a/./b/../../c/");
    string s3("/.");
    string s4("/..");
    string s5("/../");
    string s6("/a/.");
    string s7("/a//b/.");

    string s8("/..."); // bug
    string s9("/..hidden"); // bug

    cout << sol.simplifyPath(s1) << endl;
    cout << sol.simplifyPath(s2) << endl;
    cout << sol.simplifyPath(s3) << endl;
    cout << sol.simplifyPath(s4) << endl;
    cout << sol.simplifyPath(s5) << endl;
    cout << sol.simplifyPath(s6) << endl;
    cout << sol.simplifyPath(s7) << endl;
    cout << sol.simplifyPath(s8) << endl;
    cout << sol.simplifyPath(s9) << endl;

    return 0;
}
