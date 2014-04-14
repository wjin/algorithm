#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

// use adjacency matrix to store graph
class Graph
{
private:
    int vNum; // number of vertex
    int eNum; // number of edge
    vector<vector<int>> matrix; // adjacency matrix, weight type is int

    void handle(int v)
    {
        cout << v << ' ';
    }

    void dfs(vector<bool> &visited, int v)
    {
        handle(v);
        visited[v] = true;

        for (int j = 0; j < vNum; j++) {
            if (matrix[v][j] != 0 && !visited[j]) dfs(visited, j);
        }
    }

    void bfs(vector<bool> &visited, int v, queue<int> &q)
    {
        handle(v);
        visited[v] = true;
        q.push(v);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int j = 0; j < vNum; j++) {
                if (matrix[cur][j] != 0 && !visited[j]) {
                    handle(j);
                    visited[j] = true;
                    q.push(j);
                }
            }
        }
    }

public:
    Graph(int v = 10, int e = 10) : vNum(v), eNum(e),
        matrix(v, vector<int>(v, 0))
    {
    }

    // add edge i->j, and it's weight is w
    void addEdge(int i, int j, int w)
    {
        assert (i >= 1 && i <= vNum);
        assert (j >= 1 && j <= vNum);
        matrix[i - 1][j - 1] = w; // subscript is is from 0
    }

    void dfs()
    {
        vector<bool> visited(vNum, false);

        for (int i = 0; i < vNum; i++) {
            if (!visited[i]) {
                dfs(visited, i);
            }
        }
    }

    void bfs()
    {
        queue<int> q;
        vector<bool> visited(vNum, false);

        for (int i = 0; i < vNum; i++) {
            if (!visited[i]) {
                bfs(visited, i, q);
            }
        }
    }
};

int main(int argc, char *argv[])
{
#ifndef ONLINE_JUDGE
    freopen("input", "r", stdin);
    // freopen("output","w",stdout);
#endif

    int v, e;
    cin >> v >> e;
    Graph g(v, e);

    int i = 0, j = 0, w = 0;
    while (cin >> i >> j >> w) {
        g.addEdge(i, j, w);
    }

    g.dfs();
    cout << endl;

    g.bfs();
    cout << endl;

    return 0;
}
