/*

3.3

Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
Therefore, in real life, we would likely start a new stack when the previous stack
exceeds some threshold. Implement a data structure SetOf Stacks that mimics
this. SetOf Stacks should be composed of several stacks and should create a
new stack once the previous one exceeds capacity. SetOf Stacks. push() and
SetOf Stacks. pop() should behave identically to a single stack (that is, popO
should return the same values as it would if there were just a single stack).

FOLLOW UP

Implement a function popAt(int index) which performs a pop operation on
a specific sub-stack.

*/

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Solution
{
private:
    int threshold; // each stack's threshhold
    vector<list<int>> ss; // stacks

public:
    Solution(const int th = 5) : threshold(th) {}

    void push(int data)
    {
        if (ss.empty() || ss.back().size() == threshold) {
            ss.push_back(list<int>());
        }

        ss.back().push_back(data);
    }

    void pop()
    {
        if (ss.empty()) {
            throw runtime_error("stack is empty");
        }

        ss.back().pop_back();
        if (ss.back().size() == 0) {
            ss.pop_back();
        }
    }

    int top()
    {
        if (ss.empty()) {
            throw runtime_error("stack is empty");
        }

        return ss.back().back();
    }

    bool empty()
    {
        return ss.empty();
    }

    void popAt(int idx)
    {
        if (ss.empty()) {
            throw runtime_error("popAt error: stack is empty");
        }

        int curSize = threshold * (ss.size() - 1) + ss.back().size();

        if (idx > curSize) {
            throw runtime_error("error pop index");
        }

        int nth = idx / threshold; // idx belongs to nth stack
        int nthi = idx % threshold; // idx's subscript in nth stack

        ss[nth].erase(next(ss[nth].begin(), nthi));

        while (nth < ss.size() - 1) {
            ss[nth].push_back(ss[nth + 1].front());
            ss[nth + 1].pop_front();
            nth++;
        }

        if (ss.back().size() == 0) {
            ss.pop_back();
        }
    }
};

int main(int argc, char *argv[])
{
    Solution sol(3);

    for (int i = 0; i < 10; i++) {
        sol.push(i);
        cout << sol.top() << endl;
    }

    sol.popAt(5);
    // sol.popAt(100);

    while (!sol.empty()) {
        cout << sol.top() << endl;
        sol.pop();
    }

    // deliberately trigger throw
    // sol.popAt(0);

    return 0;
}
