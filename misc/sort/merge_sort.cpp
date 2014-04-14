/*
 * Merge Sort algorithm
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MergeSort
{
private:
    vector<int> m_copy; // extra space

    void merge(vector<int> &v, int start, int mid, int end)
    {
        int i = start, j = mid + 1;
        int k = start;
        copy(v.begin() + start, v.begin() + end + 1, m_copy.begin() + start);

        while (i <= mid && j <= end) {
            if (m_copy[i] <= m_copy[j])
                v[k++] = m_copy[i++];
            else {
                v[k++] = m_copy[j++];
            }
        }

        while (i <= mid)
            v[k++] = m_copy[i++];
    }

    void sort(vector<int> &v, int start, int end)
    {
        if (start < end) {
            int mid = start + ((end - start) >> 1);
            sort(v, start, mid);
            sort(v, mid + 1, end);
            merge(v, start, mid, end);
        }
    }

public:
    void sort(vector<int> &v)
    {
        m_copy.clear();
        m_copy.resize(v.size());
        sort(v, 0, v.size() - 1);
    }
};

void print_vec(vector<int> &v)
{
    for (auto t : v)
        cout << t << ' ';
    cout << endl;
}

int main(int argc, char *argv[])
{
    vector<int> v = { 100, 1, 3, 2, 10, 100, 9, 6, 0, 4, 100, 200, 60 };

    MergeSort obj;

    print_vec(v);
    obj.sort(v);
    print_vec(v);

    return 0;
}
