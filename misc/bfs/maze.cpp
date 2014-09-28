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
        bool tag; // whether visited
        State(int i = 0, int f = -1, bool t = false) : id(i), fid(f), tag(t) {}
    };

    // each grid stands for a state
    // so there is a perfect hash solution
    vector<State> s; // all states

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
    vector<State> extendState(State &cur)
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
                    && maze[x][y] == 0 && !s[id].tag) {
                s[id].tag = true;
                ret.push_back(State(id, cur.id, true));
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
    Solution() : s(LEN * LEN)
    {
    }

    void solve()
    {
        queue<State> q;
        State start(0, -1, true), end(LEN * LEN - 1);
        s[0] =  start;
        bool found = false;

        q.push(start);
        while (!q.empty() && !found) {
            start = q.front();
            q.pop();

            auto states = extendState(start);
            for (auto e : states) {
                // judge finish
                if (isTarget(e, end)) {
                    found = true;
                    s[e.id] = e;
                    break;
                }

                s[e.id] = e; // store state
                q.push(e);
            }
        }

        if (found) {
            printPath(s, end.id);
        }
    }
};

// bi-directional bfs
class Solution2
{
private:
    // visit tag
    // not access, access from start and access from end
    enum visitTag {
        NOT, START, END
    };

    // state definition
    struct State {
        int id; // current id
        int fid; // father id
        visitTag tag; // visit tag
        State(int i = 0, int f = -1, visitTag t = NOT) : id(i), fid(f), tag(t) {}
    };

    // each grid stands for a state
    // so there is a perfect hash solution
    vector<State> s; // all states

    // directions: up, right, bottom, left
    const vector<int> dx = { 0, 1, 0, -1 };
    const vector<int> dy = { -1, 0, 1, 0 };

    bool isAccessed(State &cur)
    {
        // already accessed by another direction?
        return s[cur.id].tag != NOT;
    }

    // extend State according to current State
    // extend even if it was accessed by another direction
    // so here use s[id].tag != tag)
    // judge finish in bfs main procedure so that it looks
    // more clear
    vector<State> extendState(State &cur, visitTag tag)
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
                    && maze[x][y] == 0 && s[id].tag != tag) {
                ret.push_back(State(id, cur.id, tag));
            }
        }

        return ret;
    }

    void printBefore(vector<State> &s, int id)
    {
        if (id == -1) return;

        printBefore(s, s[id].fid);
        cout << '(' << s[id].id/LEN << ", " << s[id].id%LEN << ')' << endl;
    }

    void printAfter(vector<State> &s, int id)
    {
        while (s[id].fid != -1) {
            cout << '(' << s[id].id/LEN << ", " << s[id].id%LEN << ')' << endl;
            id = s[id].fid;
        }
        cout << '(' << s[id].id/LEN << ", " << s[id].id%LEN << ')' << endl;
    }

    void printPath(vector<State> &s, int id1, int id2)
    {
        printBefore(s, id1);
        printAfter(s, id2);
    }

public:

    Solution2() : s(LEN * LEN)
    {
    }

    void solve()
    {
        queue<State> q, rq;
        State start(0, -1, START), end(LEN * LEN - 1, -1, END), t;
        bool found = false;
        int id1 = -1, id2 = -1;

        q.push(start);
        s[start.id] = start;

        rq.push(end);
        s[end.id] = end;

        while (!q.empty() && !rq.empty() && !found) {
            // search short queue first
            if (q.size() <= rq.size()) {
                t = q.front();
                q.pop();

                auto states = extendState(t, START);
                for (auto e : states) {
                    if (isAccessed(e)) {
                        found = true;
                        id2 = s[e.id].fid; //
                        s[e.id] = e; // store state

                        id1 = e.id;
                        break;
                    }

                    s[e.id] = e; // store state
                    q.push(e);
                }
            } else {
                t = rq.front();
                rq.pop();

                auto states = extendState(t, END);
                for (auto e : states) {
                    if (isAccessed(e)) {
                        found = true;
                        id1 = e.id;
                        id2 = e.fid;
                        break;
                    }

                    s[e.id] = e; // store state
                    rq.push(e);
                }
            }
        }

        if (found) {
            printPath(s, id1, id2);
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
    Solution2 sol2;

    sol.solve();
    cout << endl;
    sol2.solve();

    return 0;
}
