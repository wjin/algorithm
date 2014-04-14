#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
private:
    void permutation(string &s, vector<string> &ret, int start, int end)
    {
        if (start == end) {
            ret.push_back(s);
            return;
        }

        for (int i = start; i < end; i++) {
            swap(s[start], s[i]);
            permutation(s, ret, start + 1, end);
            swap(s[start], s[i]);
        }
    }

public:
    vector<string> permutation(string s)
    {
        vector<string> ret;
        permutation(s, ret, 0, s.size());
        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    string s("abc");

    vector<string> ret = sol.permutation(s);

    for (auto s : ret) {
        cout << s << endl;
    }

    return 0;
}
