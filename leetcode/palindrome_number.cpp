/*

 Palindrome Number

 Determine whether an integer is a palindrome. Do this without extra space.

 click to show spoilers.

 Some hints:
 Could negative integers be palindromes? (ie, -1)

 If you are thinking of converting the integer to string,
 note the restriction of using extra space.

 You could also try reversing an integer. However, if you have solved the
 problem "Reverse Integer", you know that the reversed integer might overflow.
 How would you handle such case?

 There is a more generic way of solving this problem.

 */

#include <iostream>

using namespace std;

class Solution
{
public:
    bool isPalindrome(int x)
    {
        // bug: the lowest number is 0, of course, it's not a palindrome except 0
        if (x < 0 || (x != 0 && x % 10 == 0))
            return false;

        int n = 0;
        while (x > n) {
            n = n * 10 + x % 10;
            x /= 10;
        }

        if (x == n || x == (n / 10))
            return true;
        else
            return false;
    }

    bool isPalindrome2(int x)
    {
        string s(to_string(x));

        int start = 0, end = s.size() - 1;
        while (start < end) {
            if (s[start] != s[end]) return false;
            start++;
            end--;
        }

        return true;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    cout << sol.isPalindrome(-1) << endl;
    cout << sol.isPalindrome(1) << endl;
    cout << sol.isPalindrome(11) << endl;
    cout << sol.isPalindrome(121) << endl;
    cout << sol.isPalindrome(1221) << endl;
    cout << sol.isPalindrome(123421) << endl;
    cout << sol.isPalindrome(10) << endl; // bug

    cout << sol.isPalindrome2(-1) << endl;
    cout << sol.isPalindrome2(1) << endl;
    cout << sol.isPalindrome2(11) << endl;
    cout << sol.isPalindrome2(121) << endl;
    cout << sol.isPalindrome2(1221) << endl;
    cout << sol.isPalindrome2(123421) << endl;
    cout << sol.isPalindrome2(10) << endl; // bug

    return 0;
}
