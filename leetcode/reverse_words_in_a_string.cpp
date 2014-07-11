#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    void reverseWords(string &s)
    {
        int len = s.size();
        int i = 0, j = 0, k = 0;
        vector<string> v;
        string ret;

        while (k < len) {
            i = k;

            while (i < len && s[i] == ' ') i++;

            j = i + 1;
            while (j < len && s[j] != ' ') j++;

            if (i < len) v.push_back(s.substr(i, j - i));

            k = j;
        }

        while (!v.empty()) {
            ret += v.back();
            v.pop_back();

            if (!v.empty()) ret += ' ';
        }

        s = ret;
    }
};

int main(int argc, const char *argv[])
{
    string s1("  ");
    string s2("    the sky is blue");
    string s3("the sky is blue   ");
    string s4("   the sky    is blue   ");
    Solution sol;

    sol.reverseWords(s1);
    sol.reverseWords(s2);
    sol.reverseWords(s3);
    sol.reverseWords(s4);

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;

    return 0;
}
