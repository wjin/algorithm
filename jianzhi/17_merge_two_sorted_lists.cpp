/*

 Merge Two Sorted Lists

 Merge two sorted linked lists and return it as a new list. The new list
 should be made by splicing together the nodes of the first two lists.

 */

#include <iostream>
#include <vector>

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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        ListNode dumbNode(-1);
        ListNode *p = &dumbNode;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                p->next = l1;
                p = p->next;
                l1 = l1->next;
            } else {
                p->next = l2;
                p = p->next;
                l2 = l2->next;
            }
        }

        p->next = l1 ? l1 : l2;
        return dumbNode.next;
    }

    // recursive
    ListNode *mergeTwoLists2(ListNode *l1, ListNode *l2)
    {
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode *head = nullptr;
        if (l1->val <= l2->val) {
            head = l1;
            head->next = mergeTwoLists2(l1->next, l2);
        } else {
            head = l2;
            head->next = mergeTwoLists2(l1, l2->next);
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
    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(3);
    l1->next->next = new ListNode(5);

    ListNode *l2 = new ListNode(2);
    l2->next = new ListNode(4);
    l2->next->next = new ListNode(6);

    output_list(l1);
    output_list(l2);

    Solution sol;
    ListNode *ret = sol.mergeTwoLists2(l1, l2);
    output_list(ret);

    return 0;
}
