/*

   stack with min element O(1)

*/

#include <iostream>
#include <stack>

using namespace std;

class MinStack
{
private:
    stack<int> stk;
    stack<int> minStk;

public:
    MinStack() : stk(), minStk() {}

    void push(int t)
    {
        stk.push(t);
        if(minStk.empty() || t <= minStk.top()) minStk.push(t);
    }

    void pop()
    {
        int top = stk.top();
        stk.pop();
        if (top == minStk.top()) minStk.pop();
    }

    int minElement()
    {
        return minStk.top();
    }

    int top()
    {
        return stk.top();
    }

    bool empty()
    {
        return stk.empty();
    }

    size_t size()
    {
        return stk.size();
    }

};

int main(int argc, char *argv[])
{
    MinStack stk;

    stk.push(3);
    stk.push(1);
    stk.push(0);
    stk.push(4);

    cout << stk.minElement() << endl;
    stk.pop();
    stk.pop();
    cout << stk.minElement() << endl;

    return 0;
}
