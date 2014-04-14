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
    // be carefull with last line
    string getLastLine(vector<string> &words, size_t start, size_t end, size_t len)
    {
        string line;
        for (size_t i = start; i < end; i++) {
            line += words[i];
            if (i != end - 1) {
                line += ' ';
            } else {
                size_t lineSize = line.size();
                if (lineSize != len) {
                    line += string(len - lineSize, ' ');
                }
            }
        }
        return line;
    }

    string getLine(vector<string> &words, size_t start, size_t end, size_t wordLen, size_t len)
    {
        string line;
        int totalSpace = len - wordLen; // total space count
        int interval = 0; // average space interval
        int mod = 0; // space remain after average

        if (start + 1 == end) {
            interval = totalSpace;
        } else {
            interval = totalSpace / (end - start - 1);
            mod = totalSpace % (end - start - 1);
        }

        string space(interval, ' ');
        for (size_t i = start; i < end; i++) {
            line += words[i];
            // the last word in the line
            // it may include interval or not
            if (line.size() == len) break;

            line += space;
            if (mod) {
                line += ' ';
                mod--;
            }
        }
        return line;
    }

    // justfify words[index...end)
    void justify(vector<string> &words, size_t index, size_t end, size_t len, vector<string> &ret)
    {
        if (index == end) return; // recursion end

        int wordCnt = 1;
        size_t i = 0;
        int curWordSize = words[index].size();
        for (i = index + 1; i < end; i++) {
            // + wordCnt means the least space number
            if (curWordSize + words[i].size() + wordCnt <= len) {
                wordCnt++;
                curWordSize += words[i].size();
            } else break;
        }

        if (i == end) {
            ret.push_back(getLastLine(words, index, i, len));
            return;
        } else {
            ret.push_back(getLine(words, index, i, curWordSize, len));
        }

        justify(words, i, end, len, ret); // tail recursion...
    }

public:
    vector<string> fullJustify(vector<string> &words, int L)
    {
        vector<string> ret;
        justify(words, 0, words.size(), L, ret);
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
