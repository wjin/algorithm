/*

 Insertion Sort List

 Sort a linked list using insertion sort.
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
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode dummy(-1);
        ListNode *prev = &dummy, *cur = head, *next = nullptr;

        while (cur) {
            // store next node
            next = cur->next;

            // find insert position
            while (prev->next && prev->next->val < cur->val) {
                prev = prev->next;
            }

            // insert cur
            cur->next = prev->next;
            prev->next = cur;

            // update
            cur = next;
            prev = &dummy;
        }

        return dummy.next;
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
    ListNode *list = new ListNode(3);
    list->next = new ListNode(2);
    list->next->next = new ListNode(4);
    list->next->next->next = new ListNode(1);
    list->next->next->next->next = new ListNode(5);
    Solution sol;

    print_list(list);
    list = sol.insertionSortList(list);
    print_list(list);

    return 0;
}
