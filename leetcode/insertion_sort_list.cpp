/*

 Insertion Sort List

 Sort a linked list using insertion sort.
 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) :
        val(x), next(NULL)
    {
    }
};

class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        if (head == nullptr)
            return head;

        ListNode dumbNode(-1);
        dumbNode.next = head;
        ListNode *prev = &dumbNode, *cur = prev->next;
        ListNode *p = cur->next, *q = nullptr;

        cur->next = nullptr; // split list
        while (p) {
            // store next node
            q = p->next;

            // find position to insert p
            while (cur && cur->val < p->val) {
                prev = cur;
                cur = cur->next;
            }

            // insert p between prev and cur
            p->next = cur;
            prev->next = p;

            // restore p to next node
            // set prev and cur to initial value
            p = q;
            prev = &dumbNode;
            cur = prev->next; // prev->next, not head, because we may insert node before head
        }

        return dumbNode.next;
    }
};

void print_list(ListNode *head)
{
    while (head) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    ListNode *list = new ListNode(3);
    list->next = new ListNode(2);
    list->next->next = new ListNode(4);
    list->next->next->next = new ListNode(1);
    list->next->next->next->next = new ListNode(5);
    Solution sol;

    print_list(list);
    list = sol.insertionSortList(list);
    print_list(list);

    return 0;
}
