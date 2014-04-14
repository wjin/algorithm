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

ListNode* reverse1(ListNode *head)
{
    if (head == nullptr) return nullptr;

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

ListNode* reverse2(ListNode *head)
{
    if (head == nullptr) return nullptr;

    ListNode newList(-1);
    ListNode *cur = head;
    ListNode *next = nullptr;

    while (cur) {
        next = cur->next;

        // insert node to new list
        cur->next = newList.next;
        newList.next = cur;

        cur = next;
    }

    return newList.next;
}

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

    print_list(list);
    ListNode *ret = reverse1(list);
    print_list(ret);
    print_list(reverse2(ret));

    return 0;
}
