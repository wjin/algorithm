/*

 Reverse Linked List II

 Reverse a linked list from position m to n. Do it in-place and in one-pass.

 For example:
 Given 1->2->3->4->5->NULL, m = 2 and n = 4,
 return 1->4->3->2->5->NULL.

 Note:
 Given m, n satisfy the following condition:
 1 <= m <= n <= length of list.

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
    ListNode *reverseBetween(ListNode *head, int m, int n)
    {
        if (head == NULL || m == n)
            return head;

        ListNode dumbNode(0);
        dumbNode.next = head;
        ListNode *prev = &dumbNode, *start = head;
        int scope = n - m;

        // start will point to the mth node
        while (--m) {
            prev = start;
            start = start->next;
        }

        // reverse node until nth node
        // similiar to reverse list node in k-group
        ListNode *end = start->next;
        while (scope--) {
            // link remaining node to start
            start->next = end->next;

            // insert end before start and just after prev
            end->next = prev->next;
            prev->next = end;

            // new node need to be inserted
            end = start->next;
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

    print_list(list);
    ListNode *ret = sol.reverseBetween(list, 2, 4);
    print_list(ret);

    return 0;
}
