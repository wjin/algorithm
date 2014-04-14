/*

   LRU Cache

   Design and implement a data structure for Least Recently Used (LRU) cache.
   It should support the following operations: get and set.

   get(key) - Get the value (will always be positive) of the key
   if the key exists in the cache, otherwise return -1.
   set(key, value) - Set or insert the value if the key is not already present.
   When the cache reached its capacity, it should invalidate the least recently
   used item before inserting a new item.

*/

#include <iostream>
#include <unordered_map>
#include <cassert>

using namespace std;

// double linked cycle list + hash table
// both set and get can be O(1)
// also resue list node when it is full
class LRUCache
{
private:
    // double linked list data structure
    struct ListNode {
        int key;
        int val;
        struct ListNode *prev, *next;
        ListNode(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
    };

    int maxSize; // max node number
    int curSize; // current node number
    ListNode dummy; // dummy head
    unordered_map<int, ListNode *> keyVal; // store key and corresponding node address

    // move current node to be the first node
    void move(ListNode *cur)
    {
        ListNode *prev = cur->prev;
        ListNode *next = cur->next;

        prev->next = next;
        next->prev = prev;

        dummy.next->prev = cur;
        cur->next = dummy.next;

        cur->prev = &dummy;
        dummy.next = cur;
    }

    void replace_and_move(ListNode *cur, int key, int val)
    {
        keyVal.erase(cur->key); // delete from hash table
        cur->key = key;
        cur->val = val;
        move(cur);
        keyVal[key] = cur; // add it to hash table with new key
    }

    void update_value_and_move(ListNode *cur, int val)
    {
        cur->val = val;
        move(cur);
    }

    // insert node to the head
    void insert(int key, int val)
    {
        ListNode *cur = new ListNode(key, val);

        cur->next = dummy.next;
        dummy.next->prev = cur;

        cur->prev = &dummy;
        dummy.next = cur;

        keyVal[key] = cur;
        curSize++;
    }

public:
    LRUCache(int capacity) : dummy(-1, -1)
    {
        assert(capacity > 0);
        maxSize = capacity;
        curSize = 0;
        dummy.next = dummy.prev = &dummy; // double linked cycle list
    }

    ~LRUCache()
    {
        ListNode *cur = dummy.next;
        ListNode *next = nullptr;
        while (cur != &dummy) {
            next = cur->next;
            delete cur;
            cur = next;
        }
    }

    int get(int key)
    {
        if (keyVal.find(key) == keyVal.end()) return -1;
        else { // key exist
            ListNode *cur = keyVal[key];

            // not the first node, let it be the first node
            if (dummy.next != cur) {
                move(cur);
            }

            return cur->val;
        }
    }

    void set(int key, int value)
    {
        if (keyVal.find(key) == keyVal.end()) { // key does not exist
            if (curSize < maxSize) insert(key, value); // can safely add new node
            else { // full, need to replace and move the last node
                replace_and_move(dummy.prev, key, value);
            }
        } else { // find the key, update value and move
            update_value_and_move(keyVal[key], value);
        }
    }
};

int main(int argc, char *argv[])
{
    LRUCache lru(3);

    // empty
    cout << lru.get(1) << endl; // -1

    // 1
    lru.set(1, 1);
    cout << lru.get(1) << endl; // 1

    lru.set(2, 2);
    lru.set(3, 3);
    lru.set(4, 4);

    // 4 3 2
    cout << lru.get(1) << endl; // -1

    cout << lru.get(2) << endl; // 2
    cout << lru.get(3) << endl; // 3
    cout << lru.get(4) << endl; // 4

    // 2 4 3
    cout << lru.get(2) << endl; // 2

    // 1 2 4
    lru.set(1, 1);

    cout << lru.get(3) << endl; // -1

    return 0;
}
