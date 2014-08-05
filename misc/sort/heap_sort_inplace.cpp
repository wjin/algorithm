/* heap sort in place
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class HeapSort
{
private:
    void sift_down(vector<int> &v, int vs, int i)
    {
        int j = 2 * i; // j is the left child

        while (j <= vs) { // loop until leaf
            // find max child
            if (j + 1 <= vs && v[j + 1] > v[j])
                j += 1;

            // swap if possible
            if (v[i] < v[j]) {
                swap(v[i], v[j]);
                i = j;
                j *= 2;
            } else {
                break;
            }
        }
    }

    void make_heap(vector<int> &v, int vs)
    {
        for (int i = vs / 2; i > 0; i--) {
            sift_down(v, vs, i);
        }
    }

public:
    void Sort(vector<int> &v)
    {
        int vs = v.size();

        // do not use v[0] to simplify sift_down operation
        // as when parameter i is 0, cannot find left child using 2*i
        v.insert(v.begin(), -1);

        make_heap(v, vs);

        while (vs > 1) {
            swap(v[1], v[vs]);
            vs--;
            sift_down(v, vs, 1);
        }

        v.erase(v.begin());
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

    HeapSort hs;
    hs.Sort(v);
    dump_vec(v);

    return 0;
}
