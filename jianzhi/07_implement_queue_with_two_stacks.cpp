#include <iostream>
#include <stack>
#include <queue>
#include <stdexcept>

using namespace std;

// using two stacks to implement queue
template <typename T>
class CQueue
{
private:
    stack<T> s1;
    stack<T> s2;
public:
    CQueue() {}
    ~CQueue() {}

    void appendTail(const T& node)
    {
        s1.push(node);
    }

    T deleteHead()
    {
        // s2 is empty
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        if (!s2.empty()) {
            T t = s2.top();
            s2.pop();
            return t;
        } else {
            throw runtime_error("bad operation");
        }
    }
};

// using two queues to implement stack
// elements are always in q1
// q2 is just a assistant
template <typename T>
class CStack
{
private:
    queue<T> q1;
    queue<T> q2;
public:
    CStack() {}
    ~CStack() {}

    void push(T t)
    {
        q1.push(t);
    }

    void pop()
    {
        if (q1.empty()) throw runtime_error("bad operation");

        while (q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }

        q1.pop();
        q1.swap(q2); // swap element back
    }

    T top()
    {
        if (q1.empty()) throw runtime_error("bad operation");
        return q1.back();
    }
};

int main(int argc, char *argv[])
{
    CQueue<int> q;
    q.appendTail(1);
    q.appendTail(2);

    cout << q.deleteHead() << endl;
    cout << q.deleteHead() << endl;
    q.appendTail(4);
    cout << q.deleteHead() << endl;
    // q.deleteHead();

    CStack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    s.pop();
    // s.pop();

    return 0;
}
