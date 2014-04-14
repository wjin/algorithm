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
#include <utility>

using namespace std;

class Solution
{
public:
    // O(m + n)
    bool find(const vector<vector<int>> &matrix, const int target)
    {
        int row = matrix.size();
        if (row == 0) return false;

        int col = matrix[0].size();
        if (col == 0) return false;

        int i = 0, j = col - 1;
        while (i < row && j >= 0) {
            if (matrix[i][j] == target) return true;
            if (matrix[i][j] < target) i++;
            else j--;
        }

        return false;
    }
};

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    // freopen("output","w",stdout);
#endif

    Solution sol;
    int m, n, target;

    // c++ stream cannot pass OJ
    while (scanf("%d %d", &m, &n) != EOF) {
        vector<vector<int>> v(m, vector<int>(n, 0));
        scanf("%d", &target);

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                scanf("%d", &v[i][j]);
        cout << (sol.find(v, target) ? "Yes" : "No") << endl;
    }

    return 0;
}
