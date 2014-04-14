/*
 Linked List Cycle

 Given a linked list, determine if it has a cycle in it.

 Follow up:
 Can you solve it without using extra space?

 */

#include <iostream>
#include <vector>

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
    bool hasCycle(ListNode *head)
    {
        if (head == nullptr)
            return false;

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }

        return false;
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

    cout << sol.hasCycle(l1) << endl;
    cout << sol.hasCycle(l2) << endl;
    cout << sol.hasCycle(l3) << endl;
    cout << sol.hasCycle(l4) << endl;

    return 0;
}
