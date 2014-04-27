#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <functional>

using namespace std;

// Hash Function Class used to generate a number between 0 to MAX
// leverge stl hash template class
class HashFunction
{
public:
    size_t operator()(const string& str) const
    {
        // just let ring have 100 slots: 0 to 99
        // so that it is easy to observe output
        return m_hash(str) % 100;
    }
private:
    hash<string> m_hash;
};

// according to consistent hashing algorithm
// we will map server node and data key in this ring
// and then choose appropriate server to store data
template <typename HashFunc>
class HashRing
{
public:
    HashRing(size_t replicas)
        : m_replicas(replicas)
    {
    }

    void AddNode(const string& node)
    {
        size_t slot;
        cout << "Adding server : " << node << endl;

        for (size_t i = 0; i < m_replicas; i++) {
            slot = m_hash(node + to_string(i));
            m_ring[slot] = node;
            cout << "    add virtual node " << i << " , slot " << slot << endl;
        }
    }

    void RemoveNode(const string& node)
    {
        for (size_t i = 0; i < m_replicas; i++) {
            size_t slot = m_hash(node + to_string(i));
            m_ring.erase(slot);
        }
    }

    const string& GetNode(const string& data) const
    {
        size_t slot = m_hash(data);

        // Look for the first node >= hash
        auto ite = m_ring.lower_bound(slot);
        if (ite == m_ring.end()) {
            // Wrapped around; get the first node
            ite = m_ring.begin();
        }
        return ite->second;
    }

private:
    map<size_t, string> m_ring;
    const size_t m_replicas; // virtual nodes in consistent hashing
    HashFunc  m_hash; // hash function used to map server name(node) and person's name(data)
};

struct Person {
    Person(string name="", string addr = "", size_t phone = 0) :
        m_name(name), m_addr(addr), m_phone(phone)
    {
    }

    string m_name;
    string m_addr;
    size_t m_phone;
};

class CacheServer
{
public:
    void Set(const string& key, const Person& value)
    {
        m_cache[key] = value;
    }

    Person Get(const string& key) const
    {
        Person value; // default person info
        auto ite = m_cache.find(key);
        if (ite != m_cache.end()) {
            value = ite->second;
        }
        return value;
    }

    void Remove(const string& key)
    {
        auto ite = m_cache.find(key);
        if (ite != m_cache.end()) {
            m_cache.erase(ite);
        }
    }

private:
    // data can be stored on this server
    // simply use person's name as key
    map<string, Person> m_cache;
};


int main()
{
    map<string, CacheServer> servers;
    // initialize servers according to server host name
    // here we have 4 servers used to store Person information
    servers["cache1.wjin.org"] = CacheServer();
    servers["cache2.wjin.org"] = CacheServer();
    servers["cache3.wjin.org"] = CacheServer();

    HashRing<HashFunction> ring(2);

    // person info
    vector<Person> persons = {
        { "Eric King",    "Shanghai",  1111 },
        { "Peter Will",   "Beijing",   2222 },
        { "Smith John",   "Shenzheng", 3333 },
        { "Joe Richard",  "Guangzhou", 4444 },
        { "Tim Hans",     "Chengdu",   5555 },
        { "Tom Paul",     "Hangzhou",  6666 },
        { "Kate James",   "Hangzhou",  7777 },
        { "Jim Jordan",   "Hangzhou",  8888 },
    };

    // add server to the hash ring
    for (auto ite = servers.begin(); ite != servers.end(); ++ite) {
        string name = ite->first;
        ring.AddNode(name);
    }
    cout << "-------------------------------------------------" << endl;

    // store some data
    for (auto p : persons) {
        // map person's name to ring and find an appropriate server name
        string host = ring.GetNode(p.m_name);
        if (host.empty()) throw runtime_error("No server available");
        cout << "storing " << p.m_name << " on server " << host << endl;
        servers[host].Set(p.m_name, p);
    }
    cout << "-------------------------------------------------" << endl;

    // read data from server
    for (auto p : persons) {
        string host = ring.GetNode(p.m_name); // which server?
        CacheServer server = servers[host];
        Person ret = server.Get(p.m_name); // read data
        cout << p.m_name << " information stored on server " << host << endl;
        cout << "     Name : " << ret.m_name << " Addr : " << \
             ret.m_addr << " Phone : " << ret.m_phone << endl;
    }
    cout << "-------------------------------------------------" << endl;

    // remove server cache3.wjin.org
    ring.RemoveNode("cache3.wjin.org");

    // read data again
    // as we removed server cache3, data stored on it are not available
    // we got default person info
    // however, other data won't be affected, that is consistent hashing
    for (auto p : persons) {
        string host = ring.GetNode(p.m_name);
        CacheServer server = servers[host];
        Person ret = server.Get(p.m_name); // read data
        cout << p.m_name << " information stored on server " << host << endl;
        cout << "     Name : " << ret.m_name << " Addr : " << \
             ret.m_addr << " Phone : " << ret.m_phone << endl;
    }

    return 0;
}
