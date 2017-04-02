#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// partition : O(n)
class Solution
{
private:
    int partition(vector<int> &v, int start, int end)
    {
        int sub = start + (random() % (end - start + 1));
		swap(v[sub], v[end]);

		int idx = start;
		for (int i = start; i < end; i++) {
			if (v[i] < v[end]) {
				swap(v[i], v[idx++]);
			}
		}

		swap(v[idx], v[end]);
		return idx;
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
