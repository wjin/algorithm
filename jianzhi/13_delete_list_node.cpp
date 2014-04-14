#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) :
        val(x), next(nullptr)
    {
    }
};

// average: O(1)
class Solution
{
public:
    void deleteNode(ListNode **head, ListNode *remove)
    {
        if (!head || !remove) return;

        // use remove->next to replace remove
        // and then delete remove->next
        if (remove->next) {
            ListNode *out = remove->next;
            remove->val = out->val;
            remove->next = out->next;
            delete out;
            return;
        }

        // delete last node
        if (remove == *head) { // special case if it is first node too
            delete remove;
            *head = nullptr;
        } else {
            ListNode *prev = *head;
            while (prev->next != remove) prev = prev->next; // find one before last
            prev->next = nullptr;
            delete remove;
        }
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
    Solution sol;

    ListNode *list = new ListNode(1);
    list->next = new ListNode(2);
    list->next->next = new ListNode(3);

    print_list(list);
    sol.deleteNode(&list, list->next);
    print_list(list);

    sol.deleteNode(&list, list->next);
    print_list(list);

    sol.deleteNode(&list, list);
    print_list(list);

    return 0;
}
