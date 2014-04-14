/*

 Add Two Numbers

 You are given two linked lists representing two non-negative numbers.
 The digits are stored in reverse order and each of their nodes contain
 a single digit. Add the two numbers and return it as a linked list.

 Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 Output: 7 -> 0 -> 8

 */

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) :
        val(x), next(nullptr)
    {
    }
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;

        int sum = 0, carry = 0;
        ListNode *t1 = l1, *t2 = l2;
        ListNode dumbNode(-1);
        ListNode *p = &dumbNode;

        // deal with both list nodes whey they are not null
        while (t1 && t2) {
            sum = t1->val + t2->val + carry;
            carry = sum / 10;
            sum = sum % 10;

            p->next = new ListNode(sum);
            p = p->next;
            t1 = t1->next;
            t2 = t2->next;
        }

        //deal with remaining nodes either in l1 or l2
        ListNode *q = t1 ? t1 : t2;
        while (q) {
            sum = q->val + carry;
            carry = sum / 10;
            sum = sum % 10;

            p->next = new ListNode(sum);
            p = p->next;
            q = q->next;
        }

        // there may exist one last carry
        // in such case, we must create a new node to store it
        if (carry) {
            p->next = new ListNode(1);
        }

        return dumbNode.next;
    }
};

void print_list(ListNode *list)
{
    while (list) {
        cout << list->val;
        list = list->next;
        if (list)
            cout << "->";
    }
}

int main(int argc, char* argv[])
{

    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(4);
    //l1->next->next = new ListNode(3);
    //l1->next->next->next = new ListNode(1);

    ListNode *l2 = new ListNode(8);
    l2->next = new ListNode(5);
    l2->next->next = new ListNode(7);

    print_list(l1);
    cout << endl;
    print_list(l2);
    cout << endl;

    Solution sol;
    ListNode *ret = sol.addTwoNumbers(l1, l2);
    print_list(ret);

    return 0;
}
