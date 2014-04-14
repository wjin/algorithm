/*

 Valid Palindrome

 Given a string, determine if it is a palindrome, considering only alphanumeric
 characters and ignoring cases.

 For example,
 "A man, a plan, a canal: Panama" is a palindrome.
 "race a car" is not a palindrome.

 Note:
 Have you consider that the string might be empty?
 This is a good question to ask during an interview.
 For the purpose of this problem, we define empty string as valid palindrome.

 */

#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        int len = s.size();
        if (len <= 1)
            return true; // be careful

        int start = 0, end = len - 1;
        while (start < end) {
            while (!isalnum(s[start]) && start < end) {
                start++;
            }
            while (!isalnum(s[end]) && start < end) {
                end--;
            }
            if (start == end)
                return true;
            if (s[start] == s[end] || abs(s[start] - s[end]) == 32) {
                start++;
                end--;
            } else {
                return false;
            }
        }
        return true;
    }

    bool isPalindrome2(string s)
    {
        int len = s.size();
        if (len <= 1)
            return true; // be careful

        int start = 0, end = len - 1;
        while (start < end) {
            if (!isalnum(s[start])) start++;
            else if (!isalnum(s[end])) end--;
            else { // compare two characters
                if (s[start] != s[end] && abs(s[start] - s[end]) != 32) {
                    return false;
                }
                start++;
                end--;
            }
        }
        return true;
    }
};

int main(int argc, char* argv[])
{
    string s1("A man, a plan, a canal: Panama");
    string s2("ab");
    Solution sol;

    cout << sol.isPalindrome(s1) << endl;
    cout << sol.isPalindrome(s2) << endl;

    cout << sol.isPalindrome2(s1) << endl;
    cout << sol.isPalindrome2(s2) << endl;

    return 0;
}
