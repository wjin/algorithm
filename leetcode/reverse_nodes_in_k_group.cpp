/*

 Reverse Nodes in k-Group

 Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
 If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

 You may not alter the values in the nodes, only nodes itself may be changed.
 Only constant memory is allowed.

 For example,
 Given this linked list: 1->2->3->4->5

 For k = 2, you should return: 2->1->4->3->5
 For k = 3, you should return: 3->2->1->4->5

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
    // reverse nodes between pre and end, both are not included
    ListNode* reverse(ListNode* pre, ListNode* end)
    {
        ListNode* last = pre->next; // last is the next previous node
        ListNode* cur = last->next; // pointer to current node to be reversed

        while (cur != end) {
            last->next = cur->next; //
            cur->next = pre->next;
            pre->next = cur;

            cur = last->next;
        }

        return last;
    }

    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode dumbNode(0);
        dumbNode.next = head;
        ListNode* pre = &dumbNode, *cur = head;

        int i = 0;
        while (cur) {
            if (++i % k == 0) {
                pre = reverse(pre, cur->next); // next
                cur = pre->next;
            } else
                cur = cur->next;
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
    ListNode *ret = sol.reverseKGroup(list, 2);
    print_list(ret);

    return 0;
}
