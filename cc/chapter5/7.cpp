/*

5.7

An array A[1...n] contains all the integers from 0 to n except for one number
which is missing. In this problem, we cannot access an entire integer in A with
a single operation. The elements of A are represented in binary, and the only
operation we can use to access them is 'fetch the jth bit of A[i]', which takes
constant time. Write code to find the missing integer. Can you do it in O(n) time?

Answer:

Considerint LSB:

if n % 2 == 1 then count(0s) = count(ls)
if n % 2 == 0 then count(0s) = 1 + count(ls)

Removing the number creates an imbalance of 1s and Os in the least significant bit.

1) n is odd:

remove 0: count(0s) < count(ls)
remove 1: count(0s) > count(ls)

2) n is even:

remove 0: count(0s) = count(ls)
remove 1: count(0s) > count(ls)

Conclusion:

count(0s) > count(ls)  --> remove 1
count(0s) <= count(ls) --> remove 0

Therefore, we can calculate the number of 0 and 1 in LSB from all numbers to find out
the missed number's LSB.

And then use the same way to find other bits recursively.

O(N) + O(N/2) + ... + O(1) = O(2N) = O(N)

-------

Variation:

1) An array A[1... 2^k -1] (k >= 0)

   number of 0 == number of 1 (the same way to deal with it)

2) no access limitation:  a)xor  b)sum

*/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
private:
    const int MAX_INT_BITS = 32;
    bool fetch(int num, int bit)
    {
        return !!(num & (1 << bit));
    }

public:
    int findMissingNum(vector<int> &v, int col)
    {
        if (col >= MAX_INT_BITS)
            return 0;

        vector<int> zero;
        vector<int> one;

        for (auto e : v) {
            if (fetch(e, col)) {
                one.push_back(e);
            } else {
                zero.push_back(e);
            }
        }

        if (zero.size() > one.size()) {
            return findMissingNum(one, ++col) << 1 | 1;
        } else {
            return findMissingNum(zero, ++col) << 1 | 0;
        }
    }
};

int main()
{
    const int MAX = (1 << 16);
    int times = 10;
    Solution sol;

    srand(time(nullptr));
    for (int i = 0; i < times; i++) {
        vector<int> v(MAX);
        iota(v.begin(), v.end(), 0);

        int miss = rand() % MAX;
        v.erase(v.begin() + miss);

        cout << miss << ' ' << sol.findMissingNum(v, 0) << endl;
    }

    return 0;
}
