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
    int findKthToTail(ListNode *list, int k)
    {
        if (!list || k <= 0) return -1;

        ListNode *p = list, *q = list;

        while (q && k--) { // do not swap q and k-- order
            q = q->next;
        }

        if (k > 0) return -2;

        while (q) {
            q = q->next;
            p = p->next;
        }

        return p->val;
    }

    // recursive solutioin
    void find(ListNode *l, int &k, int &ret)
    {
        if (!l) return;

        find(l->next, k, ret);
        --k;
        if (k == 0) ret = l->val;
    }

    int findKthToTail2(ListNode *list, int k)
    {
        int ret = -1;

        if (!list || k <= 0) return ret;

        find(list, k, ret);

        if (k > 0) ret = -2;
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
