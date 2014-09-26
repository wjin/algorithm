/*

   Text Justification

   Given an array of words and a length L, format the text such that
   each line has exactly L characters and is fully (left and right) justified.

   You should pack your words in a greedy approach; that is, pack as many words
   as you can in each line. Pad extra spaces ' ' when necessary so that each line
   has exactly L characters.

   Extra spaces between words should be distributed as evenly as possible.
   If the number of spaces on a line do not divide evenly between words,
   the empty slots on the left will be assigned more spaces than the slots on the right.

   For the last line of text, it should be left justified and no extra space is inserted between words.

   For example,
   words: ["This", "is", "an", "example", "of", "text", "justification."]
   L: 16.

   Return the formatted lines as:
   [
     "This    is    an",
     "example  of text",
     "justification.  "
   ]

   Note: Each word is guaranteed not to exceed L in length.


   Corner Cases:
      A line other than the last line might contain only one word. What should you do in this case?
      In this case, that line should be left-justified.

*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution
{
    // n is the number of space area
    // idx is space area id [0...n-1]
    // spaces is total space count
    void addSpace(string &s, int idx, int n, int spaces, bool lastLine)
    {
        int numOfSpaces = lastLine ? 1 : (spaces/n + ((idx < (spaces%n)) ? 1 : 0));
        s.append(numOfSpaces, ' ');
    }

    // generate line from words[start] to words[end]
    // curLen does not include spaces
    // lastLine tags whether it is the last line
    string genLine(vector<string> &words, int start, int end, int curLen, int L, bool lastLine)
    {
        string ret;

        for (int i = start; i < end; i++) {
            ret += words[i];
            addSpace(ret, i - start, end - start, L - curLen, lastLine);
        }

        // last word, also deal with start == end
        ret += words[end];
        if (ret.size() < L) {
            ret.append(L - ret.size(), ' ');
        }

        return ret;
    }

public:
    vector<string> fullJustify(vector<string> &words, int L)
    {
        vector<string> ret;
        int len = words.size();

        int curLen = 0, start = 0;
        for (int i = 0; i < len; i++) {
            if (curLen + words[i].size() + (i - start) > L) {
                // get a line
                // i - start means the number of minimum spaces
                ret.push_back(genLine(words, start, i - 1, curLen, L, false));

                // reset
                curLen = 0;
                start = i;
            }

            curLen += words[i].size();
        }

        // last line
        ret.push_back(genLine(words, start, len - 1, curLen, L, true));
        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<string> words = { "This", "is", "an", "example", "of", "text", "justification." };
    vector<string> words2 = { "a","b","c","d","e" };
    vector<string> words3 = { "Listen","to","many,","speak","to","a","few." };
    vector<string> words4 = { "What","must","be","shall","be." };

    vector<string> ret = sol.fullJustify(words, 16);
    for (auto s : ret)
        cout << s << "*" << endl;

    ret = sol.fullJustify(words2, 3); // bug
    for (auto s : ret)
        cout << s << "*" << endl;

    ret = sol.fullJustify(words3, 6); // bug
    for (auto s : ret)
        cout << s << "*" << endl;

    // just push space to the end in the last line
    ret = sol.fullJustify(words4, 12); // bug
    for (auto s : ret)
        cout << s << "*" << endl;

    return 0;
}
