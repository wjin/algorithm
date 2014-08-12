/*

3.7

An animal shelter holds only dogs and cats, and operates on a strictly "first in,
first out" basis. People must adopt either the "oldest" (based on arrival time) of
all animals at the shelter, or they can select whether they would prefer a dog or
a cat (and will receive the oldest animal of that type).

They cannot select which specificanimal they would like.

Create the data structures to maintain this system and implement
operations such as enqueue, dequeueAny, dequeueDog and
dequeueCat.You may use the built-in LinkedList data structure.

*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum AnimalKind { Dog, Cat, AnimalMax };

struct Animal {
    AnimalKind t; // animal type
    unsigned int id; // enter zoo, assign an id
    Animal(AnimalKind k, unsigned int i = -1) : t(k), id(i) {}
};

class Solution
{
private:

    unsigned int g_id; // track all animals enter this zoo
    vector<queue<Animal>> aq; // animal queues, each animal belongs to a queue

    void pop(AnimalKind t)
    {
        if (t == AnimalMax || aq[t].empty()) {
            throw runtime_error("bad operation");
        }

        Animal tmp = aq[t].front();
        aq[t].pop();

        cout << tmp.t << ' ' << tmp.id << endl;
    }

public:
    Solution() : g_id(0), aq(AnimalMax) {}

    void enque(Animal &a)
    {
        a.id = ++g_id;
        aq[a.t].push(a);
    }

    void dequeDog()
    {
        pop(Dog);
    }

    void dequeCat()
    {
        pop(Cat);
    }

    void dequeAny()
    {
        AnimalKind t = AnimalMax;
        unsigned int id = INT_MAX;

        for (int k = 0; k < AnimalMax; k++) {
            if (!aq[k].empty() && aq[k].front().id < id) {
                id = aq[k].back().id;
                t = static_cast<AnimalKind>(k);
            }
        }

        pop(t);
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    Animal dog1(Dog);
    Animal dog2(Dog);
    Animal cat1(Cat);
    Animal cat2(Cat);

    sol.enque(dog1);
    sol.enque(dog2);
    sol.enque(cat1);
    sol.enque(cat2);

    sol.dequeAny();
    sol.dequeCat();
    sol.dequeDog();
    sol.dequeCat();
    // sol.dequeCat();

    return 0;
}
