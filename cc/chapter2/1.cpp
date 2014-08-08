/*
2.1

Write code to remove duplicates from an unsorted linked list.

FOLLOW UP

How would you solve this problem if a temporary buffer is not allowed?

*/

#include <iostream>
#include <unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) :
        val(x), next(nullptr)
    {
    }
};

// O(n), O(n)
class Solution
{
public:
    ListNode* removeDup(ListNode* l)
    {
        unordered_set<int> s;
        ListNode *head = l, *pre = nullptr;

        while (l != nullptr) {
            if (s.count(l->val)) { // delete
                pre->next = l->next;
                delete l;
                l = pre->next;
            } else {
                s.insert(l->val);
                pre = l;
                l = l->next;
            }
        }

        return head;
    }
};

// Follow up:
// O(n^2), O(1)
class Solution2
{
public:
    ListNode* removeDup(ListNode* l)
    {
        ListNode *head = l, *cur = l, *pre, *q;

        while (cur != nullptr) {
            pre = cur;
            q = cur->next;

            while (q) {
                if (q->val == cur->val) {
                    pre->next = q->next;
                    delete q;
                } else {
                    pre = pre->next;
                }
                q = pre->next;
            }
            cur = cur->next;
        }

        return head;
    }
};

ListNode* createList()
{
    ListNode *list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(2);
    list->next->next->next = new ListNode(3);
    list->next->next->next->next = new ListNode(3);

    return list;
}

void dumpList(ListNode *head)
{
    while (head) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    Solution sol;
    Solution2 sol2;

    ListNode *l = createList();
    dumpList(l);
    ListNode* ret = sol.removeDup(l);
    dumpList(ret);

    ListNode *l2 = createList();
    dumpList(l2);
    ListNode* ret2 = sol2.removeDup(l2);
    dumpList(ret2);

    return 0;
}
