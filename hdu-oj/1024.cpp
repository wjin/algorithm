// io
#include <iostream>
#include <fstream>
#include <sstream>
#include <streambuf>

// c headers
#include <cctype>
#include <cerrno>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

// stl
#include <vector>
#include <string>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <functional>
#include <utility>
//#define CPP11
#ifdef CPP11
#include <forward_list>
#include <array>
#include <unordered_set>
#include <unordered_map>
#endif

// exception and limits
#include <exception>
#include <stdexcept>
#include <limits>
#include <climits>

using namespace std;

// O(mn^2), O(mn)
// cannot pass OJ
class Solution
{
public:
    int mms(vector<int> &v, int m, int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                dp[i][j] = dp[i - 1][j] + v[i - 1];

                for (int t = j - 1; t < i; t++)
                    dp[i][j] = max(dp[i][j], dp[t][j - 1] + v[i - 1]);
            }
        }

        return dp[n][m];
    }
};

// O(mn^2), O(n)
// cannot pass OJ, just optimize memory
class Solution2
{
public:
    int mms(vector<int> &v, int m, int n)
    {
        // calculate column by column
        // prev record last column value
        vector<int> dp(n + 1, 0);
        vector<int> prev(n + 1, 0);

        for (int j = 1; j <= m; j++) {
            for (int i = j; i <= n; i++) {
                dp[i] = dp[i - 1] + v[i - 1];

                for (int t = j - 1; t < i; t++)
                    dp[i] = max(dp[i], prev[t] + v[i - 1]);

            }
            copy(dp.begin(), dp.end(), prev.begin());
        }

        return dp[n];
    }
};

// O(mn), O(n)
// can pass OJ
class Solution3
{
public:
    int mms(vector<int> &v, int m, int n)
    {
        vector<int> dp(n + 1, 0);
        // prev record last max value, so only need to compare prev[i-1]
        vector<int> prev(n + 1, 0);
        int max_sum, i, j;

        for (j = 1; j <= m; j++) {
            max_sum = INT_MIN;
            for (i = j; i <= n; i++) {
                dp[i] = max(dp[i - 1], prev[i - 1]) + v[i - 1];

                prev[i - 1] = max_sum;
                max_sum = max(max_sum, dp[i]);
            }
            prev[i - 1] = max_sum;
        }

        return max_sum;
    }
};

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("1024_input", "r", stdin);
    // freopen("output","w",stdout);
#endif

    Solution3 sol;

    int m, n;

    while (cin >> m >> n) {
        vector<int> v;
        int e, i = n;
        while (i--) {
            cin >> e;
            v.push_back(e);
        }

        cout << sol.mms(v, m, n) << endl;
    }

    return 0;
}
