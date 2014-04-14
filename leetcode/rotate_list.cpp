/*

 Rotate List
 Given a list, rotate the list to the right by k places, where k is non-negative.

 For example:
 Given 1->2->3->4->5->NULL and k = 2,
 return 4->5->1->2->3->NULL.

 */

/* Answer
 * 1) k might be greater than the number of list nodes
 * 2) 'rotate the list to the right by k places' means move nodes [1, count-k]
 *    to the end one by one.
 *    Actually, we do not need to move them, we just let end->next = head to
 *    form a circle, and then disconnect the list in right place.
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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == NULL || k <= 0) return head;

        ListNode *start = head, *end = head;
        int cnt = 1;

        // count the list node as k might be greater than it
        // After that, end will be the last element, not NULL
        while (end->next) {
            cnt++;
            end = end->next;
        }

        k = k % cnt; // calculate move number
        k = cnt - k; //  [1, cnt - k]

        // form a circle
        end->next = start;

        // find the new head
        while (--k) {
            start = start->next;
        }
        head = start->next;
        start->next = NULL;

        return head;
    }

    ListNode *rotateRight2(ListNode *head, int k)
    {
        if (head == nullptr || k <= 0) return head;

        ListNode dumbNode(-1);
        dumbNode.next = head;
        ListNode *end = head;
        int cnt = 1;

        // count the list node as k might be greater than it
        // After that, end will be the last element, not NULL
        while (end->next) {
            cnt++;
            end = end->next;
        }

        k = k % cnt; // calculate move number
        k = cnt - k; //  [1, cnt - k]

        // find the split point
        // after that, cur->next is the new head
        ListNode *cur = head;
        while (--k) {
            cur = cur->next;
        }

        end->next = dumbNode.next;
        dumbNode.next = cur->next;
        cur->next = nullptr;

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
    ListNode *ret = sol.rotateRight2(list, 2);
    print_list(ret);

    return 0;
}
