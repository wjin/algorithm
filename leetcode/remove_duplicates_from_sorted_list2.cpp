/*


 Remove Duplicates from Sorted List ||

 Given a sorted linked list, delete all nodes that have duplicate numbers,
 leaving only distinct numbers from the original list.

 For example,
 Given 1->2->3->3->4->4->5, return 1->2->5.
 Given 1->1->1->2->3, return 2->3.

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

        ListNode dumbNode(-1);
        dumbNode.next = head;
        ListNode *prev = &dumbNode;

        ListNode *p1 = head, *p2 = head->next;
        while (p2) {
            while (p2 && p1->val == p2->val)
                p2 = p2->next;

            if (p1->next != p2) { // delete duplicate
                prev->next = p2;
                if (!p2)
                    return dumbNode.next; // no more element
                p1 = p2;
                p2 = p2->next;
            } else {
                prev = p1;
                p1 = p1->next;
                p2 = p2->next;
            }
        }

        return dumbNode.next;
    }

    ListNode *deleteDuplicates2(ListNode *head)
    {
        if (head == NULL)
            return head;

        ListNode dumbNode(-1);
        dumbNode.next = head;
        ListNode *prev = &dumbNode;

        ListNode *p1 = head, *p2 = head->next;
        while (p2) {
            if (p1->val != p2->val) {
                prev = p1;
                p1 = p2;
                p2 = p2->next;
            } else { // duplicate
                while (p2 && p1->val == p2->val) {
                    p1->next = p2->next;
                    // delete p2;
                    p2 = p1->next;
                }

                prev->next = p1->next;
                // delete p1;
                p1 = prev->next;
                p2 = p1 ? p1->next : nullptr;
            }
        }

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
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(2);
    //head->next->next->next->next = new ListNode(3);

    output_list(head);

    Solution sol;
    ListNode *ret = sol.deleteDuplicates(head);

    output_list(ret);

    return 0;
}
