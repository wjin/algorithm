#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string reverseWord(string s)
    {
        // first reverse total string
        reverse(s.begin(), s.end());

        // then reverse each word
        auto begin = s.begin(), end = s.end();
        while (begin <= end) { // not !=
            auto t = find(begin, end, ' ');
            reverse(begin, t);
            begin = t + 1;
        }

        return s;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    string t("I am a student.");

    cout << sol.reverseWord(t) << endl;
    return 0;
}
