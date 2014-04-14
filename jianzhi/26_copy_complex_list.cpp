/*
 Copy List with Random Pointer

 A linked list is given such that each node contains an additional random
 pointer which could point to any node in the list or null.

 Return a deep copy of the list.

 */

#include <iostream>
#include <unordered_map>

using namespace std;

/**
 * Definition for singly-linked list with a random pointer.
 */

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) :
        label(x), next(nullptr), random(nullptr)
    {
    }
};
typedef struct RandomListNode* listPtr;

class Solution
{
public:
    // using hash to map node one by one
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        if (head == nullptr)
            return nullptr;

        RandomListNode dumbNode(-1);
        listPtr p = &dumbNode;
        listPtr q = head;
        unordered_map<listPtr, listPtr> nodeMap;

        // create new nodes, nodeMap and set next pointer
        while (q) {
            p->next = new RandomListNode(q->label);
            nodeMap[q] = p->next;
            p = p->next;
            q = q->next;
        }

        // set random pointer according to nodeMap
        p = &dumbNode;
        q = head;
        while (q) {
            p->next->random = q->random ? nodeMap[q->random] : nullptr;
            p = p->next;
            q = q->next;
        }

        return dumbNode.next;
    }
};

class Solution2
{
    // awesome solution without using extra memory
    // just insert each new node behind the original node
    // so that we can set random pointer by means of it
private:
    void insert_new_node(listPtr head)
    {
        listPtr p = head;
        while (p) {
            listPtr q = new RandomListNode(p->label);
            q->next = p->next;
            p->next = q;
            p = p->next->next;
        }
    }

    void set_random_pointer(listPtr head)
    {
        listPtr p = head;
        while (p) {
            if (p->random)
                p->next->random = p->random->next;

            p = p->next->next;
        }
    }

    listPtr split_list(listPtr head)
    {
        listPtr p = head;
        RandomListNode dumbNode(-1);
        listPtr q = &dumbNode;

        while (p) {
            q->next = p->next;
            p->next = p->next->next;
            p = p->next;

            q = q->next;
            q->next = nullptr;
        }

        return dumbNode.next;
    }

public:
    RandomListNode *copyRandomList(RandomListNode *head)
    {
        insert_new_node(head);
        set_random_pointer(head);
        return split_list(head);
    }
};

listPtr create_list()
{
    listPtr head = new RandomListNode(1);
    head->next = new RandomListNode(2);
    head->next->next = new RandomListNode(3);
    head->random = head->next->next;
    head->next->random = nullptr;
    head->next->next->random = head;

    return head;
}

void print_list(listPtr head)
{
    while (head) {
        cout << head->label;
        if (head->random)
            cout << ',' << head->random->label;
        cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main(int argc, char* argv[])
{
    Solution sol;
    Solution2 sol2;

    listPtr head = create_list();
    print_list(head);

    listPtr clone = sol.copyRandomList(head);
    print_list(clone);

    listPtr clone2 = sol2.copyRandomList(head);
    print_list(clone2);

    print_list(head);

    return 0;
}
