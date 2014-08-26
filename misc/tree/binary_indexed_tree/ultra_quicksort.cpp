/*

Ultra-QuickSort

Description

In this problem, you have to analyze a particular sorting algorithm.
The algorithm processes a sequence of n distinct integers by swapping
two adjacent sequence elements until the sequence is sorted in ascending
order.

For the input sequence

9 1 0 5 4 ,

Ultra-QuickSort produces the output

0 1 4 5 9

Your task is to determine how many swap operations Ultra-QuickSort needs to
perform in order to sort a given input sequence.

Input

The input contains several test cases. Every test case begins with a line that
contains a single integer n < 500,000 -- the length of the input sequence.
Each of the the following n lines contains a single integer 0 <= a[i] <= 999,999,999,
the i-th input sequence element. Input is terminated by a sequence of length n = 0.
This sequence must not be processed.

Output

For every input sequence, your program prints a single line containing an integer number
op, the minimum number of swap operations necessary to sort the given input sequence.

Sample Input

5
9
1
0
5
4
3
1
2
3
0

Sample Output

6
0

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    struct node {
        int val; // value
        int id; // order in the input stream
    };

    static bool cmp(const node &lhs, const node &rhs)
    {
        return lhs.val < rhs.val;
    }

    int MAX;
    vector<int> c; // binary indexed tree

public:
    int lowbit(int x)
    {
        return x & (-x);
    }

    void update(int x, int num)
    {
        while (x <= MAX) {
            c[x] += num;
            x += lowbit(x);
        }
    }

    int read(int x)
    {
        int sum = 0;
        while (x) {
            sum += c[x];
            x -= lowbit(x);
        }
        return sum;
    }

    void solveOne(int n)
    {
        MAX = n;
        c.clear();
        c.resize(n + 1);
        vector<node> v(n + 1);

        // read data
        for(int i = 1; i <= n; i++) {
            cin >> v[i].val;
            v[i].id = i;
        }

        // discretize input
        sort(v.begin() + 1, v.end(), cmp);
        vector<int> discrete(n + 1);
        for(int i = 1; i <= n; i++) {
            discrete[v[i].id] = i;
        }

        // counting result
        // i is the input index
        // read(discrete[i]) is the number that little than or equal to discrete[i]
        // i - read(discrete[i]) is the number that grater than discrete[i]
        long long ret = 0;
        for(int i = 1; i <= n; i++) {
            update(discrete[i], 1);
            ret += (i - read(discrete[i]));
        }

        cout << ret << endl;
    }

    void solve()
    {
        int n = 0;
        while (cin >> n, n != 0) {
            solveOne(n);
        }
    }
};

int main(int argc, const char* argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    // freopen("output","w",stdout);
#endif

    Solution sol;

    sol.solve();

    return 0;
}
