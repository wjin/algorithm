#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

// using logic and, or, not to implement bitset
class BitSet
{
    // int has 32 bits
    //   n / 32 --> n >> 5
    //   n % 32 ---> n & 0x1f
private:
    vector<int> v;
    const int shift = 5;
    const int mask = 0x1f;
    int bits;

public:
    BitSet(const int n = 10000)
    {
        bits = n;
        v.resize((bits >> shift) + 1, 0);
    }

    void set(int n)
    {
        assert(n < bits);
        v[n >> shift] |= (1 << (n & mask));
    }

    void clear(int n)
    {
        assert(n < bits);
        v[n >> shift] &= (~(1 << (n & mask)));
    }

    bool test(int n)
    {
        assert(n < bits);
        return v[n >> shift] & (1 << (n & mask));
    }
};

int main(int argc, char* argv[])
{
    BitSet obj;

    for (int i = 0; i < 5; i++) {
        obj.set(i);
        cout << obj.test(i) << endl;
        obj.clear(i);
        cout << obj.test(i) << endl;
    }

    return 0;
}
