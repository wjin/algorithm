/*

 Trie

*/

#include <iostream>
#include <vector>

using namespace std;

class Trie
{
private:
    struct TrieNode {
        int cnt; // cnt != 0 means key ending with this node exists
        vector<TrieNode *> next;
        TrieNode(const int charSet = 26): cnt(0), next(charSet)
        {
        }
    };

    TrieNode root;

    void destroy(TrieNode *t)
    {
        if (t) {
            for (auto e : t->next) {
                destroy(e);
            }
            delete t;
        }
    }

    bool _insert(TrieNode *t, const char *key)
    {
        while (*key) {
            int ch = *key - 'a';
            if (!t->next[ch]) {
                TrieNode *p = new TrieNode();
                if (!p) return false; // no memory
                t->next[ch] = p;
            }
            t = t->next[ch];
            key++;
        }
        t->cnt++;
        return true;
    }

    bool _remove(TrieNode *t, const char *key)
    {
        TrieNode *parent;
        int ch;
        while (*key) {
            ch = *key - 'a';
            if (!t->next[ch]) return false; // key does not exist

            parent = t;
            t = t->next[ch];
            key++;
        }

        t->cnt--;
        if (t->cnt == 0) {
            for (auto e : t->next) {
                if (e) return true;
            }

            // this node was not used by any other nodes
            // delete it
            delete t;
            parent->next[ch] = nullptr;
        }
        return true;
    }

    bool _search(TrieNode *t, const char *key)
    {
        while (*key) {
            int ch = *key - 'a';
            if (!t->next[ch]) return false; // key does not exist

            t = t->next[ch];
            key++;
        }
        return !!t->cnt;
    }

public:
    ~Trie()
    {
        for (auto t : root.next) {
            if(t) destroy(t);
        }
    }

    bool insert(const char *key)
    {
        if (key == nullptr || *key == '\0') return false;
        return _insert(&root, key);
    }

    bool remove(const char *key)
    {
        if (key == nullptr || *key == '\0') return false;
        return	_remove(&root, key);
    }

    bool search(const char *key)
    {
        if (key == nullptr || *key == '\0') return false;
        return _search(&root, key);
    }
};

int main(int argc, char* argv[])
{
    Trie trie;

    char keys[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};
    char output[][32] = {"Not present in trie", "Present in trie"};

    // insert elements to trie
    for(size_t i = 0; i < sizeof(keys)/ sizeof(keys[0]); i++) {
        trie.insert(keys[i]);
    }

    // Search for different keys
    cout << "the:" << output[trie.search("the")] << endl;
    cout << "these:" << output[trie.search("these")] << endl;
    cout << "their:" << output[trie.search("their")] << endl;
    cout << "thaw:" << output[trie.search("thaw")] << endl;

    trie.remove("their");
    // remove keys
    for(size_t i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
        if (trie.remove(keys[i])) {
            cout << keys[i] << " will be removed." << endl;
        } else {
            cout << keys[i] << " does not exist." << endl;
        }
    }

    // search again
    for(size_t i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
        if (trie.search(keys[i])) {
            cout << keys[i] << " error" << endl;
        }
    }

    return 0;
}
