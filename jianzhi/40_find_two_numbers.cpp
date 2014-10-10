#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution
{
private:
    int findFirstOneIdx(int n)
    {
        int idx = 0;
        while ((n & 0x1) == 0) idx++;
        return idx;
    }

    bool isSet(int n, int idx)
    {
        return (n >> idx) & 0x1;
    }

public:
    pair<int, int> findTwoNumber(vector<int> &v)
    {
        int xorAll = 0;

        for (auto e : v) {
            xorAll ^= e;
        }

        int idx = findFirstOneIdx(xorAll);
        pair<int, int> ret;

        for (auto e : v) {
            if (isSet(e, idx)) {
                ret.first ^= e;
            } else {
                ret.second ^= e;
            }
        }

        return ret;
    }
};

int main(int argc, char* argv[])
{
    vector<int> v = { 3, 3, 2, 4, 4, 5 };
    Solution sol;

    pair<int, int> ret = sol.findTwoNumber(v);
    cout << ret.first << ' ' << ret.second << endl;

    return 0;
}
