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
private:
    int getListLength(ListNode *l)
    {
        int ret = 0;
        while (l) {
            l = l->next;
            ret++;
        }

        return ret;
    }
public:
    int firstCommonNode(ListNode *l1, ListNode *l2)
    {
        int len1 = getListLength(l1);
        int len2 = getListLength(l2);
        int gap = abs(len1 - len2);

        while (gap) {
            if (len1 > len2) {
                l1 = l1->next;
            } else {
                l2 = l2->next;
            }
            gap--;
        }

        while (l1 != l2) {
            l1 = l1->next;
            l2 = l2->next;
        }

        return l1->val;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    ListNode *l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    l1->next->next->next->next = new ListNode(5);

    ListNode *l2 = new ListNode(0);
    l2->next = l1->next;

    cout << sol.firstCommonNode(l1, l2) << endl;

    return 0;
}
