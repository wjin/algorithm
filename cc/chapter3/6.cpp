/*

3.6

Write a program to sort a stack in ascending order (with biggest items on top).
You may use at most one additional stack to hold items, but you may not copy
the elements into any other data structure (such as an array). The stack supports
the following operations: push, pop, peek, and isEmpty.

*/

#include <iostream>
#include <deque>
#include <stack>
#include <functional>

using namespace std;

class Solution
{
private:
    template<typename T>
    void do_sort(stack<int> &s, const T &cmp)
    {
        stack<int> t;
        while (!s.empty()) {
            int tmp = s.top();
            s.pop();
            while (!t.empty() && cmp(tmp, t.top())) {
                s.push(t.top());
                t.pop();
            }
            t.push(tmp);
        }

        s = t;
    }

public:
    void ascending(stack<int> &s)
    {
        do_sort(s, less<int>());
    }

    void descending(stack<int> &s)
    {
        do_sort(s, greater<int>());
    }
};

void dump_stack(stack<int> &s)
{
    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
    cout << endl;
}

int main()
{
    deque<int> v = { 1, 6, 8, 2, 7, 5 };

    // be careful about stack's default container is deque.
    stack<int> s1(v), s2(v);
    Solution sol;

    sol.ascending(s1);
    sol.descending(s2);

    dump_stack(s1);
    dump_stack(s2);

    return 0;
}
