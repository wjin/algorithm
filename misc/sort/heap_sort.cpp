/* heap data structure and heap sort
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// max heap
class Heap
{
private:
    vector<int> m_data; // heap data
    size_t m_size; // heap size

    void sift_up(int i)
    {
        while (i > 1 && m_data[i] > m_data[i / 2]) {
            swap(m_data[i], m_data[i / 2]);
            i /= 2;
        }
    }

    void sift_down(int i)
    {
        int j = 2 * i; // j is the left child

        while (j <= m_size) { // loop until leaf
            // find max child
            if (j + 1 <= m_size && m_data[j + 1] > m_data[j])
                j += 1;

            // swap if possible
            if (m_data[i] < m_data[j]) {
                swap(m_data[i], m_data[j]);
                i = j;
                j *= 2;
            } else {
                break;
            }
        }
    }

    void make_heap()
    {
        for (int i = m_size / 2; i > 0; i--) {
            sift_down(i);
        }
    }

public:
    Heap(vector<int> &v)
    {
        m_size = v.size();

        // do not use m_data[0] to simplify sift_down operation
        // as when parameter i is 0, cannot find left child using 2*i
        m_data.resize(m_size + 1);
        m_data[0] = -1;

        copy(v.begin(), v.end(), m_data.begin() + 1);
        make_heap();
    }

    void push_heap(int val)
    {
        m_data.push_back(val);
        m_size++;
        sift_up (m_size);
    }

    int pop_heap()
    {
        int val = get_top();
        swap(m_data[1], m_data[m_size]);
        m_data.pop_back();
        m_size--;
        sift_down(1);
        return val;
    }

    int get_top()
    {
        return m_data[1];
    }

    int get_size()
    {
        return m_size;
    }
};

class HeapSort
{
private:
    Heap hp;

public:
    HeapSort(vector<int> &v) : hp(v)
    {
    }

    vector<int> sort()
    {
        vector<int> ret;
        while (hp.get_size()) {
            ret.push_back(hp.pop_heap());
        }
        return ret;
    }
};

void dump_vec(vector<int> &v)
{
    for (auto e : v) {
        cout << e << ' ';
    }
    cout << endl;
}

int main(int argc, char *argv[])
{
    vector<int> v;
    v.resize(10);
    iota(v.begin(), v.end(), 1);

    dump_vec(v);
    random_shuffle(v.begin(), v.end());
    dump_vec(v);

    HeapSort hs(v);
    vector<int> ret = hs.sort();
    dump_vec(ret);

    return 0;
}
