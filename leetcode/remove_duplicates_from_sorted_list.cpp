/*

 Remove Duplicates from Sorted List

 Given a sorted linked list, delete all duplicates such that
 each element appear only once.

 For example,
 Given 1->1->2, return 1->2.
 Given 1->1->2->3->3, return 1->2->3.

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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (head == NULL)
            return head;

        ListNode *p1 = head, *p2 = head->next;

        while (p2) {
            while (p2 && p1->val == p2->val) {
                // might free memory here
                p2 = p2->next;
            }

            p1->next = p2;
            if (p2 == NULL) break;

            p1 = p2;
            p2 = p2->next;
        }

        return head;
    }

    ListNode *deleteDuplicates2(ListNode *head)
    {
        if (head == NULL)
            return head;

        ListNode *p1 = head, *p2 = head->next;

        while (p2) {
            if (p2->val == p1->val) {
                p1->next = p2->next;
                // delete p2;
                p2 = p1->next;
            } else {
                p1 = p2;
                p2 = p2->next;
            }
        }

        return head;
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
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    Solution sol;

    output_list(head);
    ListNode *ret = sol.deleteDuplicates(head);
    output_list(ret);

    return 0;
}
