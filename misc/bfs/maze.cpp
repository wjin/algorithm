/*

http://poj.org/problem?id=3984

Description

定义一个二维数组：

int maze[5][5] = {

	0, 1, 0, 0, 0,

	0, 1, 0, 1, 0,

	0, 0, 0, 0, 0,

	0, 1, 1, 1, 0,

	0, 0, 0, 1, 0,

};

它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，要求编程序找出从左上角到右下角的最短路线。

Input

一个5 × 5的二维数组，表示一个迷宫。数据保证有唯一解。

Output

左上角到右下角的最短路径，格式如样例所示。

Sample Input

0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 1 1 1 0
0 0 0 1 0

Sample Output

(0, 0)
(1, 0)
(2, 0)
(2, 1)
(2, 2)
(2, 3)
(2, 4)
(3, 4)
(4, 4)

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int LEN = 5;
vector<vector<int>> maze(LEN, vector<int>(LEN, 0));

class Solution
{
private:
    // state definition
    struct State {
        int id; // current id
        int fid; // father id

        State(int i = 0, int f = -1) : id(i), fid(f) {}
    };

    // directions: up, right, bottom, left
    // sometimes, we may have 8 directions
    const vector<int> dx = { 0, 1, 0, -1 };
    const vector<int> dy = { -1, 0, 1, 0 };

    // judge wheter it is finished
    bool isTarget(State &cur, State &end)
    {
        return cur.id == end.id;
    }

    // extend State according to current State
    vector<State> extendState(vector<bool> &used, State &cur)
    {
        vector<State> ret;
        int x, y, id;
        for (int i = 0; i < dx.size(); i++) {
            x = cur.id / LEN;
            y = cur.id % LEN;

            x += dx[i];
            y += dy[i];
            id = x * LEN + y;

            if (x >= 0 && x < LEN && y >= 0 && y < LEN
                    && maze[x][y] == 0 && !used[id]) {
                used[id] = true;
                ret.push_back(State(id, cur.id));
            }
        }

        return ret;
    }

    void printPath(vector<State> &s, int id)
    {
        if (id == -1) return;

        printPath(s, s[id].fid);
        cout << '(' << s[id].id/LEN << ", " << s[id].id%LEN << ')' << endl;
    }

public:
    void solve()
    {
        // each grid stands for a state
        // so there is a perfect hash solution
        vector<State> s(LEN * LEN); // all states
        vector<bool> used(LEN * LEN, false); // state tag

        queue<State> q;
        State start(0), end(LEN * LEN - 1);
        bool found = false;

        q.push(start);
        used[0] = true;

        // bfs
        while (!q.empty() && !found) {
            start = q.front();
            q.pop();

            auto states = extendState(used, start);
            for (auto e : states) {
                s[e.id] = e; // store state
                q.push(e);

                // judge finish
                if (isTarget(e, end)) {
                    found = true;
                    break;
                }
            }
        }

        if (found) {
            printPath(s, end.id);
        }
    }
};

int main(int argc, char* argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    // freopen("output","w",stdout);
#endif

    for (int i = 0; i < LEN; i++) {
        for (int j = 0; j < LEN; j++) {
            cin >> maze[i][j];
        }
    }

    Solution sol;
    sol.solve();

    return 0;
}
