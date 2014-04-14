/*

   Restore IP Addresses

   Given a string containing only digits, restore it by
   returning all possible valid IP address combinations.

   For example:
   Given "25525511135",

   return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    void dfs(string &s, size_t start, size_t step, string ip, vector<string> &ret)
    {
        if (start == s.size() && step == 4) {
            ip.resize(ip.size() - 1); // delete the last '.'
            ret.push_back(ip);
            return;
        }

        // invalid, cut
        if (s.size() - start <  4 - step) return;
        if (s.size() - start > (4 - step) * 3) return;

        int n = 0;
        for (size_t i = start; (i < start + 3) && i < s.size(); i++) {
            n = n * 10 + s[i] - '0';
            if (n < 256) {
                string t(s.substr(start, i - start + 1));
                dfs(s, i + 1, step + 1, ip + t + '.', ret);
            }
            // 0 is valid only, do not extend to 0*
            if (n == 0) break; // be careful
        }
    }

    vector<string> restoreIpAddresses(string s)
    {
        vector<string> ret;
        string ip;
        dfs(s, 0, 0, ip, ret);
        return ret;
    }
};

void print_ret(vector<string> &ret)
{
    for (auto e : ret)
        cout << e << endl;
}

int main(int argc, char *argv[])
{
    Solution sol;
    string s("25525511135");

    vector<string> ret = sol.restoreIpAddresses(s);
    print_ret(ret);

    return 0;
}
