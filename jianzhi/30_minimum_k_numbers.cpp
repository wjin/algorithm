#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// partition : O(n)
class Solution
{
private:

    // generates number in the range [start, end]
    int getRandom(int start, int end)
    {
        default_random_engine generator;
        uniform_int_distribution<int> distribution(start, end);
        return distribution(generator);
    }

    int partition(vector<int> &num, int start, int end)
    {
        int pivot = num[getRandom(start, end)];

        while (start < end) {
            if (num[start] < pivot) start++;
            else if (num[end] > pivot) end--;
            else {
                swap(num[start], num[end]);
            }
        }

        num[start] = pivot;
        return start;
    }

public:
    void minimumK(vector<int> &num, int k)
    {
        int len = num.size();
        int start = 0, end = len - 1;
        int idx = partition(num, 0, end);

        while (idx != k - 1) {
            if (idx > k -1) {
                end = idx - 1;
            } else {
                start = idx + 1;
            }
            idx = partition(num, start, end);
        }
    }
};

// heap: O(nlogk)
class Solution2
{
public:
    void minimumK(vector<int> &num, int k)
    {
        // construct heap of num[0...k-1]
        make_heap(num.begin(), num.begin() + k);

        // insert element num[k...end] to heap
        for (int i = k; i < num.size(); i++) {
            swap(num[k], num[i]);
            push_heap(num.begin(), num.begin() + k + 1);
            pop_heap(num.begin(), num.begin() + k + 1);
        }
    }
};

// stl multiset : O(nlogk)
class Solution3
{
public:
    void minimumK(vector<int> &num, size_t k)
    {
        multiset<int, greater<int>> ms;

        for (auto e : num) {
            if (ms.size() < k) ms.insert(e);
            else {
                auto ite = ms.begin();
                if (e < *ite) {
                    ms.erase(ite);
                    ms.insert(e);
                }
            }
        }

        for_each(ms.begin(), ms.end(), [](int n) {
            cout << n << ' ';
        });
        cout << endl;
    }
};

void print_vector(vector<int> & v)
{
    for (auto e : v)
        cout << e << ' ';
    cout << endl;
}

int main(int argc, char *argv[])
{
    // Solution sol;
    // Solution2 sol;
    Solution3 sol;
    vector<int> num = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    srand(unsigned(time(0)));
    random_shuffle(num.begin(), num.end());
    print_vector(num);

    sol.minimumK(num, 3);
    print_vector(num);

    random_shuffle(num.begin(), num.end());
    print_vector(num);
    sol.minimumK(num, 7);
    print_vector(num);

    return 0;
}
