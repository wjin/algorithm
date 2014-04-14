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

class Solution
{
public:
    int findKthToTail(ListNode *list, size_t k)
    {
        if (!list || k <= 0) return -1;

        ListNode dummy(-11);
        dummy.next = list;
        ListNode *p = &dummy, *q = &dummy;

        while (k && q) {
            q = q->next;
            k--;
        }

        // don't use k == 0
        if (!q) return -1; // k > list length

        while (q) {
            q = q->next;
            p = p->next;
        }

        return p->val;
    }

    // recursive solutioin
    int find(ListNode *list, size_t k,int &ret)
    {
        if (!list) return 0;

        size_t t = find(list->next, k, ret) + 1;
        if (t == k) ret = list->val;
        return t;
    }

    int findKthToTail2(ListNode *list, size_t k)
    {
        int ret = -1;

        if (!list || k <= 0) return ret;

        find(list, k, ret);

        return ret;
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
    cout << sol.findKthToTail(list, 0) << endl;
    cout << sol.findKthToTail(list, 1) << endl;
    cout << sol.findKthToTail(list, 2) << endl;
    cout << sol.findKthToTail(list, 3) << endl;
    cout << sol.findKthToTail(list, 4) << endl;

    cout << sol.findKthToTail2(list, 0) << endl;
    cout << sol.findKthToTail2(list, 1) << endl;
    cout << sol.findKthToTail2(list, 2) << endl;
    cout << sol.findKthToTail2(list, 3) << endl;
    cout << sol.findKthToTail2(list, 4) << endl;

    return 0;
}
