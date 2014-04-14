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
    void outputReverse(ListNode *list)
    {
        if (list == nullptr)
            return;
        outputReverse(list->next);
        cout << list->val << endl;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    ListNode *l = new ListNode(1);
    l->next = new ListNode(2);
    l->next->next = new ListNode(3);

    sol.outputReverse(l);

    return 0;
}
