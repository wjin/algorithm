/*

3.4 Hanoi

In the classic problem of the Towers of Hanoi, you have 3 rods and N disks
of different sizes which can slide onto any tower. The puzzle starts with
disks sorted in ascending order of size from top to bottom
(e.g., each disk sits on top of an even larger one).

You have the following constraints:

Only one disk can be moved at a time.
A disk is slid off the top of one rod onto the next rod.
A disk can only be placed on top of a larger disk.
Write a program to move the disks from the first rod to
the last using Stacks

*/

#include <iostream>
#include <stack>

using namespace std;

// recursively
class Solution
{
private:
    void moveAction(int id, int src, int dst)
    {
        // move disk
        cout << "Move disk "<< id << " from ";
        cout << src << " to " << dst << endl;
    }

public:
    void hanoi(int n, int src, int dst, int buf)
    {
        if (n == 1) { // ending condition
            moveAction(n, src, dst);
            return;
        }

        hanoi(n - 1, src, buf, dst);
        moveAction(n, src, dst);
        hanoi(n - 1, buf, dst, src);
    }
};

// unrecursively
class Solution2
{
private:
    struct state {
        int start; // disk start
        int end; // disk end
        int src; // rod source
        int dst; // rod destination
        int buf; // rod buffer
        state(int st = -1, int e = -1, int sr = -1, int d = -1, int b = -1) :
            start(st), end(e), src(sr), dst(d), buf(b)
        {
        }
    };

    void moveAction(const state &s)
    {
        // move disk
        cout << "Move disk "<< s.start << " from ";
        cout << s.src << " to " << s.dst << endl;
    }

public:
    void hanoi(int n, int src, int dst, int buf)
    {
        stack<state> s;
        state t;

        // stack initial state
        s.push(state(1, n, src, dst, buf));

        while (!s.empty()) {
            t = s.top();
            s.pop();

            // this rod has one disk, just move
            if (t.start == t.end) {
                moveAction(t);
                continue;
            }

            // reversely push states to stack compared with recursive solution
            s.push(state(t.start, t.end - 1, t.buf, t.dst, t.src));
            s.push(state(t.end, t.end, t.src, t.dst, t.buf));
            s.push(state(t.start, t.end - 1, t.src, t.buf, t.dst));
        }
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    Solution2 sol2;
    int n = 3;

    sol.hanoi(n, 0, 2, 1);
    cout << endl;
    sol2.hanoi(n, 0, 2, 1);

    return 0;
}
