/*

11.7 Circus Pyramid

A circus is designing a tower routine consisting of people standing atop one
another's shoulders. For practical and aesthetic reasons, each person must be
both shorter and lighter than the person below him or her. Given the heights
and weights of each person in the circus, write a method to compute the largest
possible number of people in such a tower.

EXAMPLE:

Input (ht,wt): (65, 100) (70, 150) (56, 90) (75, 190) (60, 95) (68, 110)

Output:The longest tower is length 6 and includes from top to bottom:

(56, 90) (60,95) (65,100) (68,110) (70,150) (75,190)

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
private:
    struct Person {
        int ht; // height
        int wt; // weight

        Person(const int h = 0, const int w = 0) : ht(h), wt(w) {}
    };

    static bool cmp(const Person &lhs, const Person &rhs)
    {
        return lhs.ht < rhs.ht;
    }

    const int MAX = 1000;
    vector<int> c; // binary indexed tree

public:
    Solution() : c(MAX) {}

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

    void solve()
    {
        int n;
        cin >> n;
        vector<Person> v(n);

        for(int i = 0; i < n; i++) {
            cin >> v[i].ht >> v[i].wt;
        }

        sort(v.begin(), v.end(), cmp);

        int ret = INT_MIN;
        for (auto e : v) {
            ret = max(ret, read(e.wt));
            update(e.wt, 1);
        }

        cout << ret + 1<< endl; // +1 means including himself
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
