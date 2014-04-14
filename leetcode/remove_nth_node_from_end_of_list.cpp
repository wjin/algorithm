/*

 Remove Nth Node From End of List

 Given a linked list, remove the nth node from the end of list and return its head.

 For example,

 Given linked list: 1->2->3->4->5, and n = 2.

 After removing the second node from the end, the linked list becomes 1->2->3->5.
 Note:
 Given n will always be valid.
 Try to do this in one pass.

 */

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head == NULL || n <= 0)
            return head;

        ListNode dumbNode(-1);
        ListNode *p = &dumbNode;
        p->next = head;
        ListNode *q = p->next;  // q points to head

        while (n-- && q)
            q = q->next;

        if (n > 0)
            return head; // n beyond list size, invalid

        while (q) {
            p = p->next;
            q = q->next;
        }

        // dumb node makes it easy
        // delete, regardless of whether it is first, middle or last node
        p->next = p->next->next;
        return dumbNode.next;
    }
};

void output_list(ListNode *head)
{
    while (head) {
        cout << head->val << "->";
        head = head->next;
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    output_list(head);

    Solution sol;
    ListNode *ret = sol.removeNthFromEnd(head, 1);

    output_list(ret);

    return 0;
}
