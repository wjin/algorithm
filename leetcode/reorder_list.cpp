/*

 Reorder List

 Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

 You must do this in-place without altering the nodes' values.

 For example,
 Given {1,2,3,4}, reorder it to {1,4,2,3}.

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

void print_list(ListNode *head);

class Solution
{
public:
    // reverse list in place
    ListNode* reverse_list(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;

        ListNode *prev = nullptr;
        ListNode *cur = head;
        ListNode *next = nullptr;

        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        return prev;
    }

    // cut list into two lists from the middle point
    // the first list is equal or one bigger than the second one
    // return the second list
    ListNode* split_list(ListNode *head)
    {
        ListNode dumbNode(-1);
        dumbNode.next = head;
        ListNode *slow = &dumbNode, *fast = slow;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        fast = slow->next;
        slow->next = nullptr;
        return fast;
    }

    void merge_list(ListNode *l1, ListNode *l2)
    {
        ListNode *p = l1, *q = nullptr;
        while (l2) {
            q = l2;
            l2 = l2->next;

            // insert list
            q->next = p->next;
            p->next = q;

            p = p->next->next;
        }
    }

    void reorderList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
            return;

        ListNode *l1 = head;
        ListNode *l2 = nullptr;

        // l2 won't be null here
        l2 = split_list(l1);
        l2 = reverse_list(l2);
        merge_list(l1, l2);
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
    sol.reorderList(list);
    print_list(list);

    return 0;
}
