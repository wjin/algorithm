/*

   Clone Graph

   Clone an undirected graph. Each node in the graph contains a label
   and a list of its neighbors.

   OJ's undirected graph serialization:
   Nodes are labeled uniquely.

   We use # as a separator for each node, and , as a separator for node label
   and each neighbor of the node.
   As an example, consider the serialized graph {0,1,2#1,2#2,2}.

   The graph has a total of three nodes, and therefore contains three parts as separated by #.

   First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
   Second node is labeled as 1. Connect node 1 to node 2.
   Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
   Visually, the graph looks like the following:

     1
    / \
   /   \
   0 --- 2
        / \
        \_/

*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

typedef UndirectedGraphNode graphNode;
typedef UndirectedGraphNode* graphPtr;

// according to the problem, graph is connected obviously

// BFS
class Solution
{
    graphPtr bfs(graphPtr head)
    {
        unordered_map<graphPtr, graphPtr> clone;
        queue<graphPtr> q;

        q.push(head);
        clone[head] = new graphNode(head->label);

        // traverse each node and then copy
        // nodes in the queue have already been copied
        while (!q.empty()) {
            graphPtr cur = q.front();
            q.pop();

            for (auto e : cur->neighbors) {
                if (clone.count(e) != 0) { // already copied
                    clone[cur]->neighbors.push_back(clone[e]);
                } else { // clone e
                    graphPtr copy = new graphNode(e->label);
                    clone[e] = copy;
                    q.push(e);
                    clone[cur]->neighbors.push_back(copy);
                }
            }
        }

        return clone[head];
    }

public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
    {
        if (node == nullptr) return node;
        return bfs(node);
    }
};

// DFS
class Solution2
{
    void dfs(graphPtr cur, unordered_map<graphPtr, graphPtr> &clone)
    {
        // clone current node
        if (clone.count(cur) == 0) {
            clone[cur] = new graphNode(cur->label);
        }

        // clone neighbors
        for (auto e : cur->neighbors) {
            if (clone.count(e) == 0) { // clone e
                dfs(e, clone);
            }
            clone[cur]->neighbors.push_back(clone[e]);
        }
    }

public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node)
    {
        if (node == nullptr) return node;

        unordered_map<graphPtr, graphPtr> clone;
        dfs(node, clone);
        return clone[node];
    }
};

graphPtr create_graph()
{
    graphPtr p0 = new graphNode(0);
    graphPtr p1 = new graphNode(1);
    graphPtr p2 = new graphNode(2);

    p0->neighbors.push_back(p1);
    p0->neighbors.push_back(p2);

    p1->neighbors.push_back(p0);
    p1->neighbors.push_back(p2);

    p2->neighbors.push_back(p0);
    p2->neighbors.push_back(p1);
    p2->neighbors.push_back(p2);

    return p0;
}

void print_graph(graphPtr head)
{
    queue<graphPtr> q;
    unordered_set<graphPtr> visited;

    q.push(head);
    visited.insert(head);
    graphPtr cur = nullptr;

    while (!q.empty()) {
        cur = q.front();
        q.pop();

        cout << cur->label << ' ';
        cout << cur << ' ';
        for (auto e : cur->neighbors) {
            cout << e << ' ';
            if (visited.count(e) == 0) {
                q.push(e);
                visited.insert(e);
            }
        }
        cout << endl;
    }
}

int main(int argc, char *argv[])
{
    Solution sol;
    Solution2 sol2;

    graphPtr g = create_graph();
    graphPtr clone = sol.cloneGraph(g);
    graphPtr clone2 = sol2.cloneGraph(g);

    print_graph(g);
    print_graph(clone);
    print_graph(clone2);

    return 0;
}
