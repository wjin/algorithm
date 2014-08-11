/*

3.1

Describe how you could use a single array to implement three stacks?

*/

#include <iostream>
#include <vector>

using namespace std;

// simple solution: three stacks have the same size
// [0, sz)
// [sz, 2*sz)
// [2*sz, 3*sz)
class Solution
{
private:
    int sz; // per stack size
    int sn; // stack number, here it is 3
    vector<int> se; // stack element array
    vector<int> st; // per stack top

    int getTopPosition(int sid)
    {
        return st[sid] + sz * sid;
    }

public:
    Solution(int z = 10, int n = 3) : sz(z), sn(n), se(sz * sn), st(sn, -1)
    {
    }

    void push(int sid, int data)
    {
        if (st[sid] + 1 >= sz) {
            throw runtime_error("stack is full");
        }

        st[sid]++;
        se[getTopPosition(sid)] = data;
    }

    void pop(int sid)
    {
        if (st[sid] == -1) {
            throw runtime_error("stack is empty");
        }

        st[sid]--;
    }

    int top(int sid)
    {
        if (st[sid] == -1) {
            throw runtime_error("stack is empty");
        }

        return se[getTopPosition(sid)];
    }

    bool isEmpty(int sid)
    {
        return st[sid] == -1;
    }
};

int main(int argc, char *argv[])
{
    int sz = 2;
    int sn = 3;

    Solution sol(sz, sn);

    for (int i = 0; i < sn; i++) {
        sol.push(i, i);
    }

    for (int i = 0; i < sn; i++) {
        sol.push(i, i * 2);
    }

    for (int i = 0; i < sn; i++) {
        cout << sol.top(i) << endl;
    }

    // sol.push(0, 1);

    return 0;
}
