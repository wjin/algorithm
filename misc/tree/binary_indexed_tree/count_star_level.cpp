/*

Stars

Description

Astronomers often examine star maps where stars are represented by points on a plane and each
star has Cartesian coordinates. Let the level of a star be an amount of the stars that are not
higher and not to the right of the given star. Astronomers want to know the distribution of the
levels of the stars.

You are to write a program that will count the amounts of the stars of each level on a given map.

Input

The first line of the input file contains a number of stars N (1<=N<=15000). The following N lines describe
coordinates of stars (two integers X and Y per line separated by a space, 0<=X,Y<=32000). There can be only
one star at one point of the plane. Stars are listed in ascending order of Y coordinate. Stars with equal Y
coordinates are listed in ascending order of X coordinate.

Output

The output should contain N lines, one number per line. The first line contains amount of stars of the level 0,
the second does amount of stars of the level 1 and so on, the last line contains amount of stars of the level N-1.

Sample Input

5
1 1
5 1
7 1
3 3
5 5

Sample Output

1
2
1
1
0

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
private:
    const int MAX = 32002;
    vector<int> c; // binary indexed tree
    vector<int> level; // record each level's number

public:
    Solution() : c(MAX), level(MAX) {}

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

    // read returns cumulative sum of c[1]...c[x]
    // here it is the level of this star
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
        int x, y, n;

        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> x >> y;

            // as points are sorted by y coordinate with ascending order,
            // for each point, only count points before it in the input stream
			// x + 1 is to avoid case: x=0
            level[read(x + 1)]++;
            update(x + 1, 1);
        }

        for(int i = 0; i < n; i++)
            cout << level[i] << endl;
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
