#include <iostream>
#include <stdexcept>

using namespace std;

// implement stack with list
template <typename T>
class StackWithList
{
private:
    struct ListNode {
        T val;
        ListNode *next;
        ListNode(int x) :
            val(x), next(nullptr)
        {
        }
    };

    ListNode dummy;
    size_t stkSize;

public:
    StackWithList(): dummy(-1), stkSize(0) {}
    ~StackWithList()
    {
        ListNode *cur = dummy.next;
        ListNode *t = nullptr;
        while (cur) {
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
        dummy.next = node;
        stkSize++;
    }

    void pop()
    {
        if (!dummy.next) throw runtime_error("bad operation");
        ListNode *remove = dummy.next;
        dummy.next = dummy.next->next;

        delete remove;
        stkSize--;
    }

    T top()
    {
        if (!dummy.next) throw runtime_error("bad operation");
        return dummy.next->val;
    }

    bool empty()
    {
        return dummy.next == nullptr;
    }

    size_t size()
    {
        return stkSize;
    }

    void dump()
    {
        ListNode *cur = dummy.next;
        while (cur) {
            cout << cur->val << ' ';
            cur = cur->next;
        }
        cout << endl;
    }
};

int main(int argc, char *argv[])
{
    StackWithList<int> s;

    // s.pop();
    cout << s.size() << endl;
    s.dump();

    s.push(1);
    s.dump();

    s.push(2);
    s.dump();

    s.push(3);
    s.dump();

    cout << s.size() << endl;
    cout << s.top() << endl;

    s.pop();
    cout << s.size() << endl;
    cout << s.top() << endl;
    s.dump();

    return 0;
}
