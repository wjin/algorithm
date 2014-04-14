/*

 Partition List

 Given a linked list and a value x, partition it such that all nodes
 less than x come before nodes greater than or equal to x.

 You should preserve the original relative order of the nodes in each of the two partitions.

 For example,
 Given 1->4->3->2->5->2 and x = 3,
 return 1->2->2->4->3->5.

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
    ListNode *partition(ListNode *head, int x)
    {
        ListNode dumbLeft(0), dumbRight(0);
        ListNode *ptrLeft = &dumbLeft, *ptrRight = &dumbRight;
        ListNode *cur = head;

        while (cur) {
            if (cur->val < x) {
                ptrLeft->next = cur;
                ptrLeft = cur;
            } else {
                ptrRight->next = cur;
                ptrRight = cur;
            }

            cur = cur->next;
        }

        ptrRight->next = NULL;
        ptrLeft->next = dumbRight.next;

        return dumbLeft.next;
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
    ListNode *list = new ListNode(3);
    list->next = new ListNode(2);
    list->next->next = new ListNode(5);
    list->next->next->next = new ListNode(4);
    list->next->next->next->next = new ListNode(1);
    Solution sol;

    output_list(list);
    ListNode *ret = sol.partition(list, 4);
    output_list(ret);

    return 0;
}
