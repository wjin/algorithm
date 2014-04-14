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

// recursive solution
ListNode* reverse3(ListNode *cur, ListNode *tail)
{
    if (!cur) return tail;

    ListNode *remain = cur->next;
    cur->next = tail;
    return reverse3(remain, cur);
}
ListNode* reverse3_rec(ListNode *head)
{
    return reverse3(head, nullptr);
}

// recursive solution
void reverse4_rec(ListNode *&t) // &
{
    if (!t || !t->next) return;

    ListNode *remain = t->next;
    reverse4_rec(remain);

    t->next->next = t;
    t->next = nullptr;
    t = remain;
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

    ret = reverse2(ret);
    print_list(ret);

    ret = reverse3_rec(ret);
    print_list(ret);

    reverse4_rec(ret);
    print_list(ret);

    return 0;
}
