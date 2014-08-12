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

    bool empty()
    {
        return s1.empty() && s2.empty();
    }

    int size()
    {
        return s1.size() + s2.size();
    }

    void push(const T& t)
    {
        s1.push(t);
    }

    void pop()
    {
        if (empty()) {
            throw runtime_error("bad operation");
        }

        // s2 is empty
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        s2.pop();
    }

    T front()
    {
        if (empty()) {
            throw runtime_error("bad operation");
        }

        // s2 is empty
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        T t = s2.top();
        return t;
    }

    T back()
    {
        if (empty()) {
            throw runtime_error("bad operation");
        }

        if (s1.empty()) {
            while (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }

        T t = s1.top();
        return t;
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

    bool empty()
    {
        return q1.empty();
    }

    int size()
    {
        return q1.size();
    }

    void push(const T &t)
    {
        q1.push(t);
    }

    void pop()
    {
        if (q1.empty()) {
            throw runtime_error("bad operation");
        }

        while (q1.size() != 1) {
            q2.push(q1.front());
            q1.pop();
        }

        q1.pop();
        q1.swap(q2); // swap elements back
    }

    T top()
    {
        if (q1.empty()) {
            throw runtime_error("bad operation");
        }

        return q1.back();
    }
};

int main(int argc, char *argv[])
{
    CQueue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    cout << q.front() << endl;
    cout << q.back() << endl;

    q.pop();
    cout << q.front() << endl;
    cout << q.back() << endl;
    q.pop();
    q.pop();
    // q.pop();

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
