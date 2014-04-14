#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
#include <stdexcept>

using namespace std;

// use adjacency list to store it
class Graph
{
private:
    // edge node
    struct EdgeNode {
        int v; // vertex pointed by this edge
        int w; // weight
        EdgeNode *next; // next edge linked to the same head
        EdgeNode(int _v = 0, int _w = 0) : v(_v), w(_w), next(nullptr) {}
    };

    // vertex node
    struct VertexNode {
        int v; // vertex info, here we just store its id
        EdgeNode *edge; // adjacency edge
        VertexNode(int _v = 0) : v(_v), edge(nullptr) {}
    };

    int vNum; // number of vertex
    int eNum; // number of edge
    vector<VertexNode> list; // adjacency head list

    void handle(int v)
    {
        cout << v << ' ';
    }

    void dfs(vector<bool> &visited, int v)
    {
        handle(v);
        visited[v] = true;

        EdgeNode *cur = list[v].edge;
        while (cur) {
            if (!visited[cur->v]) dfs(visited, cur->v);
            cur = cur->next;
        }
    }

    void bfs(vector<bool> &visited, int v, queue<int> &q)
    {
        handle(v);
        visited[v] = true;
        q.push(v);

        while (!q.empty()) {
            int cv = q.front(); // current vertex
            q.pop();

            EdgeNode *cur = list[cv].edge;

            while (cur) {
                if (!visited[cur->v]) { // don't forget judge
                    handle(cur->v);
                    visited[cur->v] = true;
                    q.push(cur->v);
                }

                cur = cur->next;
            }
        }
    }

public:
    Graph(int v = 10, int e = 10) : vNum(v), eNum(e),
        list(v)
    {
        for (int i = 0; i < v; i++) {
            list[i].v = i;
        }
    }

    // add edge i->j, and it's weight is w
    // note that input vertex starts from 1
    void addEdge(int i, int j, int w)
    {
        assert (i >= 1 && i <= vNum);
        assert (j >= 1 && j <= vNum);

        if (!list[i - 1].edge) { // first edge
            list[i - 1].edge = new EdgeNode(j - 1, w);
            if (!list[i - 1].edge) throw runtime_error("no memory");
            return;
        }

        EdgeNode *cur = list[i - 1].edge; // get first edge
        while (cur->next) cur = cur->next; // traverse to last edge
        cur->next = new EdgeNode(j - 1, w); // insert new edge in the end
        if (!cur->next) throw runtime_error("no memory");
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
