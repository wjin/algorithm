/*

 Swap Nodes in Pairs

 Given a linked list, swap every two adjacent nodes and return its head.

 For example,
 Given 1->2->3->4, you should return the list as 2->1->4->3.

 Your algorithm should use only constant space.
 You may not modify the values in the list, only nodes itself can be changed

 */

#include <iostream>

using namespace std;

/*
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
    ListNode *swapPairs(ListNode *head)
    {
        if (head == nullptr)
            return head;

        ListNode dumbNode(-1);
        dumbNode.next = head;

        ListNode *prev = &dumbNode, *p = head, *q = p->next;

        while (q) {
            p->next = q->next;
            q->next = prev->next;
            prev->next = q;
            prev = p;
            p = p->next;

            if (!p) break; //
            q = p->next;
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
    ListNode *list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);
    list->next->next->next = new ListNode(4);
    list->next->next->next->next = new ListNode(5);

    Solution sol;
    print_list(sol.swapPairs(list));

    return 0;
}
