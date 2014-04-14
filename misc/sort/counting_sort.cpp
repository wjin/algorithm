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
#include <forward_list>
#include <array>
#include <unordered_set>
#include <unordered_map>

// exception and limits
#include <exception>
#include <stdexcept>
#include <limits>
#include <climits>

using namespace std;

// counting sort
// elements' scope should be determinate
class Solution
{
public:
    // here 0 <= v[i] <= 10
    void sort(vector<int> &v, int maxNum)
    {
        vector<int> count(maxNum + 1, 0);
        for (auto  e : v)
            count[e]++;

        int i = 0;
        for (int j = 0; i < v.size() && j < count.size(); j++) {
            while (count[j]) {
                v[i++] = j;
                count[j]--;
            }
        }
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v { 2, 3, 1, 5, 2, 1, 9, 7, 7, 3 };

    sol.sort(v, 10);
    for (auto  e : v)
        cout << e << ' ';

    cout << endl;
    return 0;
}
