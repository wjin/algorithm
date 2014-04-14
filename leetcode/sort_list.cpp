/*

   Sort List

   Sort a linked list in O(n log n) time using constant space complexity.

*/

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// recursive quick sort: TLE
// it is not constant space either
// just for practice
class Solution
{
public:
    void partition(ListNode *&start, ListNode *&pivot, ListNode *&postPivot)
    {
        ListNode small(-1), big(-1);

        pivot = start; // choose first node as pivot
        start = start->next;
        pivot->next = nullptr;

        ListNode *t = nullptr; // temporarily store start->next
        while (start) {
            t = start->next;

            // insert node reversely to small and big list respectively
            if (start->val <= pivot->val) { // insert node to small list, first half
                start->next = small.next;
                small.next = start;
            } else { // insert node to second list
                start->next = big.next;
                big.next = start;
            }

            start = t;
        }

        // only pivot must be nullptr
        start = small.next;
        postPivot = big.next;
    }

    ListNode* quickSortList(ListNode *start)
    {
        if (!start || !start->next) {
            return start;
        } else {
            // only pivot will never be nullptr
            // start, postPivot might be nullptr after partition
            ListNode *pivot = nullptr, *postPivot = nullptr;
            partition(start, pivot, postPivot);

            ListNode *l1 = quickSortList(start);
            ListNode *l2 = quickSortList(postPivot);

            if (!l1) { // first list is nullptr
                pivot->next = l2;
                return pivot;
            }

            // connect
            ListNode *head = l1;
            while (l1->next) l1 = l1->next; // find the tail of first list
            l1->next = pivot; // connect pivot
            pivot->next = l2; // connect second list

            return head;
        }
    }

    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr) return head;
        return quickSortList(head);
    }
};

// merge sort
// can pass OJ
class Solution2
{
public:
    int getLength(ListNode *head)
    {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }

    // merge two lists and connect new list to prev->next
    // also update tail
    void merge(ListNode *l1, ListNode *l2, ListNode *prev, ListNode **tail)
    {
        ListNode *p = prev;
        while (l1 || l2) {
            if (!l1 || (l2 && l2->val < l1->val)) {
                p->next = l2;
                l2 = l2->next;
            } else {
                p->next = l1;
                l1 = l1->next;
            }
            p = p->next;
        }

        *tail = p;
    }

    // split a sub list with length len
    ListNode *split(ListNode &dummy, int len)
    {
        ListNode *ret = nullptr;
        ListNode *prev = &dummy, *cur = dummy.next;

        while (len && cur) {
            prev = cur;
            cur = cur->next;
            len--;
        }

        prev->next = nullptr;
        ret = dummy.next;
        dummy.next = cur;
        return ret;
    }

    ListNode* mergeSortList(ListNode *head)
    {
        ListNode dummy(-1);
        dummy.next = head;
        int len = getLength(head);
        int step = 1;

        ListNode dummy2(-1); // store temp merged list for each step
        ListNode *tail = nullptr, *tailTemp = nullptr;
        while (step < len) {
            tail = nullptr;
            tailTemp = nullptr;
            while (dummy.next) { // exist non-merged list node
                ListNode *l1 = split(dummy, step);
                ListNode *l2 = split(dummy, step);

                // merge them
                if (!tail) {
                    merge(l1, l2, &dummy2, &tail);
                } else {
                    merge(l1, l2, tail, &tailTemp);
                    tail = tailTemp;
                }
            }

            step *= 2; // update step
            swap(dummy.next, dummy2.next); // swap list back
        }
        return dummy.next;
    }

    ListNode* sortList(ListNode *head)
    {
        if (!head || !head->next) return head;
        return mergeSortList(head);
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
    Solution2 sol2;

    ListNode *list = new ListNode(3);
    list->next = new ListNode(3);
    list->next->next = new ListNode(2);
    list->next->next->next = new ListNode(2);
    list->next->next->next->next = new ListNode(1);

    ListNode *list1 = new ListNode(3);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(3);
    list1->next->next->next = new ListNode(1);
    list1->next->next->next->next = new ListNode(1);
    list1->next->next->next->next->next = new ListNode(1);
    list1->next->next->next->next->next->next = new ListNode(2);
    list1->next->next->next->next->next->next->next = new ListNode(2);
    list1->next->next->next->next->next->next->next->next = new ListNode(1);
    list1->next->next->next->next->next->next->next->next->next = new ListNode(2);

    ListNode *ret = nullptr;
#if 0
    print_list(list);
    ret = sol.sortList(list);
    print_list(ret);

    print_list(list1);
    ret = sol.sortList(list1);
    print_list(ret);
#endif

    print_list(list);
    ret = sol2.sortList(list);
    print_list(ret);

    print_list(list1);
    ret = sol2.sortList(list1);
    print_list(ret);

    return 0;
}
