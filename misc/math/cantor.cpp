/*

 Permutation Sequence

 The set [1,2,3,…,n] contains a total of n! unique permutations.

 By listing and labeling all of the permutations in order,
 We get the following sequence (ie, for n = 3):

 "123"
 "132"
 "213"
 "231"
 "312"
 "321"

 Given n and k, return the kth permutation sequence.
 Note: Given n will be between 1 and 9 inclusive.

 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
 X=a[n]*(n-1)!+a[n-1]*(n-2)!+...+a[i]*(i-1)!+...+a[2]*1!+a[1]*0!
 a is integer, and 0<=a[i]<i(1<=i<=n)
 this equation maps a natural number

 i.e:，3 5 7 4 1 2 9 6 8 maps 98884.
       because X=2*8!+3*7!+4*6!+2*5!+0*4!+0*3!+2*2!+0*1!+0*0! = 98884.

 why?

 1) considering first number 3, so there are two numbers(1, 2) less than 3,
    and permutation leading with them is 8!, so it is 2 * 8!
 2) considering 5, there are four numbers(1, 2 ,3 , 4) less than it,
    and 3 was used in the first item, so there remains 3 numbers usable.
	that is 3 * 7!

 Application:
  Give a number(include digit 1...n), we can calculate its postion in permutation.

 */
class Solution
{
public:
    long long factorial(int n)
    {
        long long product = 1;
        for (int i = 2; i <= n; i++) {
            product *= i;
        }
        return product;
    }

    string getPermutation(int n, int k)
    {
        if (n < 1 || k < 1)
            return "";

        string orig, ret;
        for (int i = 1; i <= n; i++) {
            orig += i + '0';
        }

        // Cantor encode, minus one to start from 0
        // because we will use %
        --k;
        int base = factorial(n - 1); // (n-1)!

        for (int i = n - 1; i > 0; k %= base, base /= i, --i) {
            // judge it belongs to which permutation
            // the sub permu, leading with orig[sub]
            int sub = k / base;
            ret += orig[sub];
            orig.erase(sub, 1);
        }
        ret += orig[0]; // i == 0, the last one

        return ret;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    for (int i = 1; i <= 6; i++) {
        cout << sol.getPermutation(3, i) << endl;
    }

    return 0;
}
