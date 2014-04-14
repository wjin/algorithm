#include <iostream>

using namespace std;

template <typename T>
class List
{
private:
    // list node definition
    struct ListNode {
        T val;
        ListNode *prev, *next;
        ListNode(T x) :
            val(x), prev(nullptr), next(nullptr)
        {
        }
    };

    ListNode dummy;

public:
    List(): dummy(-1) {}

    // insert element to list reversely
    bool insert(T v)
    {
        ListNode *p = new ListNode(v);
        if (p == nullptr) return false; // no memory

        if (dummy.next) {
            dummy.next->prev = p;
        }

        p->next = dummy.next;
        p->prev = &dummy;
        dummy.next = p;

        return true;
    }

    // remove node if exist, do not consider duplicate nodes
    bool remove(T v)
    {
        ListNode *cur = dummy.next;
        while (cur && cur->val != v) {
            cur = cur->next;
        }

        if (cur) { // find it, delete
            ListNode *p = cur->next;

            if (p) {
                p->prev = cur->prev;
            }

            cur->prev->next = p;
            delete cur;
            return true;
        }

        return false; // node does not exist
    }

    void dump()
    {
        ListNode *t = dummy.next;
        while (t) {
            cout << t->val << "->";
            t = t->next;
        }
        cout << endl;

        t = &dummy;
        while (t->next) t = t->next;
        while (t != &dummy) {
            cout << t->val << "->";
            t = t->prev;
        }
        cout << endl;
    }
};

int main(int argc, char *argv[])
{

    List<int> list;

    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.insert(4);
    list.dump();

    list.remove(2);
    list.dump();

    list.remove(4);
    list.dump();

    list.remove(1);
    list.dump();

    list.remove(3);
    list.dump();

    list.remove(3);
    list.dump();

    return 0;
}
