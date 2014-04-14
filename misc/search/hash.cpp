#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for hash node
 */
template <typename T>
struct HashNode {
    T key; // key
    HashNode *next; // linked list to deal with conflict
    HashNode(T k) :
        key(k), next(nullptr)
    {
    }
};

// simple hash table implementation
template <typename T>
class Hash
{
private:
    size_t bucket; // hash table entry(bucket) number
    size_t count; // hash node number
    vector<HashNode<T>*> table;

    // simply hash function
    size_t hash(T key)
    {
        return key % bucket;
    }


public:
    Hash(size_t s = 10) : bucket(s), count(0)
    {
        table.resize(bucket);
        table.resize(bucket);
    }

    ~Hash()
    {
        HashNode<T> *p = nullptr;
        for (auto e : table) {
            while (e) {
                p = e->next;
                delete e;
                e = p;
            }
        }
    }

    // insert element to bucket, keep them in order if conflict
    bool insert(T key)
    {
        HashNode<T> *p = new HashNode<T>(key);
        if (p == nullptr) return false; // no memory

        // get bucket
        size_t idx = hash(key);
        count++;
        if (!table[idx]) {
            table[idx] = p;
            return true;
        }

        HashNode<T> *prev = nullptr;
        HashNode<T> *cur = table[idx];

        // find insert position in bucket idx
        // keep key in order if they are in the same bucket
        while (cur && cur->key < key) {
            prev = cur;
            cur = cur->next;
        }

        p->next = cur;
        if (prev) {
            prev->next = p;
        } else {
            table[idx] = p;
        }
        return true;
    }

    bool find(T key)
    {
        // get bucket
        size_t idx = hash(key);
        HashNode<T> *cur = table[idx];

        while (cur && cur->key < key) {
            cur = cur->next;
        }

        if (!cur || cur->key != key) return false;
        else return true;
    }

    bool remove(T key)
    {
        // get bucket
        size_t idx = hash(key);
        HashNode<T> *cur = table[idx];
        HashNode<T> *prev = nullptr;

        while (cur && cur->key < key) {
            prev = cur;
            cur = cur->next;
        }

        if (!cur || cur->key != key) return false; // not find

        // find it
        if (!prev) { // delete first node in bucket idx
            table[idx] = cur->next;
        } else {
            prev->next = cur->next;
        }

        delete cur;
        count--;
        return true;
    }

    void dump()
    {
        cout << "hash node count: " << count << endl;
        for (auto e : table) {
            while (e) {
                cout << e->key;
                if (e->next) cout << ' ';
                e = e->next;
            }
            cout << "$" << endl;
        }
        cout << "-----------------------" << endl;
    }
};

int main(int argc, char *argv[])
{
    Hash<int> h;
    h.insert(1);
    h.insert(2);
    h.insert(3);
    h.insert(4);
    h.insert(11);
    h.insert(12);
    h.dump();

    h.remove(1);
    h.remove(11);
    h.dump();

    cout << h.find(1) << endl;
    cout << h.find(2) << endl;

    return 0;
}
