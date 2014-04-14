/*

 Merge k Sorted Lists

 Merge k sorted linked lists and return it as one sorted list.
 Analyze and describe its complexity.

 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) :
        val(x), next(NULL)
    {
    }
};

bool comp(const ListNode*lhs, const ListNode *rhs)
{
    return lhs->val > rhs->val;
}

class Solution
{
public:
    // k lists, each list has n elements
    // O(nk*log(k))
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        vector<ListNode *> v;

        // eliminate null list
        for (auto t : lists) {
            if (t != NULL)
                v.push_back(t);
        }

        // construct min heap
        make_heap(v.begin(), v.end(), comp);

        ListNode dumbNode(-1);
        ListNode *p = &dumbNode;
        ListNode *cur = nullptr;

        while (!v.empty()) {
            pop_heap(v.begin(), v.end(), comp);
            cur = v.back();

            p->next = cur;
            p = p->next;

            // advance current list or delete it when it reaches end
            cur = cur->next;
            if (cur == nullptr) {
                v.pop_back();
            } else {
                v[v.size() - 1] = cur;
                push_heap(v.begin(), v.end(), comp);
            }
        }

        return dumbNode.next;
    }
};

int main(int argc, char* argv[])
{
    ListNode *t1 = new ListNode(0);
    t1->next = new ListNode(2);
    t1->next->next = new ListNode(4);

    ListNode *t2 = new ListNode(1);
    t2->next = new ListNode(3);
    t2->next->next = new ListNode(5);

    ListNode *t3 = new ListNode(10);
    t3->next = new ListNode(11);
    t3->next->next = new ListNode(12);

    vector<ListNode *> lists = { t1, t2, t3 };
    Solution sol;

    ListNode * ret = sol.mergeKLists(lists);

    while (ret != NULL) {
        cout << ret->val << "->";
        ret = ret->next;
    }

    return 0;
}
