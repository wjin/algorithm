/*

 Linked List Cycle ||

 Given a linked list, return the node where the cycle begins.
 If there is no cycle, return null.

 Follow up:
 Can you solve it without using extra space?

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
    ListNode *detectCycle(ListNode *head)
    {
        if (head == nullptr)
            return false;

        ListNode dumbNode(-1);
        dumbNode.next = head;
        ListNode *slow = &dumbNode;
        ListNode *fast = slow;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            // cycle exist
            if (slow == fast) {
                slow = &dumbNode;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }

        return nullptr;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    ListNode *l1 = new ListNode(1);

    ListNode *l2 = new ListNode(1);
    l2->next = l2;

    ListNode *l3 = new ListNode(1);
    l3->next = new ListNode(2);
    l3->next->next = new ListNode(3);

    ListNode *l4 = new ListNode(1);
    l4->next = new ListNode(2);
    l4->next->next = new ListNode(3);
    l4->next->next->next = l4->next;

    ListNode *ret = sol.detectCycle(l1);
    cout << (ret ? ret->val : -1) << endl;

    ret = sol.detectCycle(l2);
    cout << (ret ? ret->val : -1) << endl;

    ret = sol.detectCycle(l3);
    cout << (ret ? ret->val : -1) << endl;

    ret = sol.detectCycle(l4);
    cout << (ret ? ret->val : -1) << endl;

    return 0;
}
