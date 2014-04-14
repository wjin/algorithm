#include <iostream>
#include <stdexcept>

using namespace std;

// implement queue with list

// double linked cycle list as we need to
// get queue head when pop queue
template <typename T>
class QueueWithList
{
private:
    struct ListNode {
        T val;
        ListNode *prev, *next;
        ListNode(int x) :
            val(x), prev(nullptr), next(nullptr)
        {
        }
    };

    ListNode dummy;
    size_t queSize;

public:
    QueueWithList(): dummy(-1), queSize(0)
    {
        dummy.next = dummy.prev = &dummy;
    }

    ~QueueWithList()
    {
        ListNode *cur = dummy.next;
        ListNode *t = nullptr;

        while (cur != &dummy) {
            t = cur->next;
            delete cur;
            cur = t;
        }
    }

    void push(const T &t)
    {
        ListNode *node = new ListNode(t);
        if (!node) throw runtime_error("no memory");

        node->next = dummy.next;
        dummy.next->prev = node;

        dummy.next = node;
        node->prev = &dummy;

        queSize++;
    }

    void pop()
    {
        if (dummy.prev == &dummy) throw runtime_error("bad operation");

        ListNode *remove = dummy.prev;

        remove->prev->next = remove->next;
        remove->next->prev = remove->prev;

        delete remove;
        queSize--;
    }

    T front()
    {
        if (dummy.prev == &dummy) throw runtime_error("bad operation");
        return dummy.prev->val;
    }

    T back()
    {
        if (dummy.next == &dummy) throw runtime_error("bad operation");
        return dummy.next->val;
    }

    bool empty()
    {
        return dummy.next == &dummy;
    }

    size_t size()
    {
        return queSize;
    }

    void dump()
    {
        ListNode *cur = dummy.next;
        while (cur != &dummy) {
            cout << cur->val << ' ';
            cur = cur->next;
        }
        cout << endl;
    }
};

int main(int argc, char *argv[])
{
    QueueWithList<int> q;

    // q.front();
    // q.back();
    cout << q.size() << endl;
    q.dump();

    q.push(1);
    q.dump();

    q.push(2);
    q.dump();

    q.push(3);
    q.dump();

    cout << q.size() << endl;
    cout << q.front() << endl;
    cout << q.back() << endl;

    q.pop();
    cout << q.size() << endl;
    cout << q.front() << endl;
    cout << q.back() << endl;
    q.dump();

    return 0;
}
