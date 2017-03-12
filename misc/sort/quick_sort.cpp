/*
 * Quick Sort algorithm
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class QuickSort
{
private:
    int partition(vector<int> &v, int start, int end)
    {
        if (start == end) return start;

        int pivot = start + (random() % (end - start + 1));
        swap(v[start], v[pivot]);

        int i = start, j =  i + 1;
        while (j <= end) {
            if (v[j] > v[start]) j++;
            else {
                i++;
                if (i != j) {
                    swap(v[i], v[j]);
                }
                j++;
            }
        }

        swap(v[i], v[start]);
        return i;
    }

    int partition2(vector<int> &v, int start, int end)
    {
        if (start == end) return start;

        int idx = start + (random() % (end - start + 1));
        int pivot = v[idx];
        int low = start, high = end;
        swap(v[idx], v[end]); // swap pivot to end, not start

        // after loop, low will be illegal
        while (low < high) {
            while (low < high && v[low] <= pivot) low++; // =
            while (low < high && v[high] >= pivot) high--; // =

            if (low < high) swap(v[low], v[high]);
        }

        // swap pivot to its position
        swap(v[low], v[end]);

        return low;
    }

    int partition3(vector<int> &v, int start, int end)
    {
        if (start == end) return start;

        int idx = start + (random() % (end - start + 1));
        int pivot = v[idx];
        int low = start, high = end;
        swap(v[idx], v[end]); // swap pivot to end, not start

        // after loop, low will be illegal
        while (low < high) {
            if (v[low] <= pivot) low++; // =
            else if (v[high] >= pivot) high--; // =
            else {
                swap(v[low], v[high]);
            }
        }

        // swap pivot to its position
        swap(v[low], v[end]);
        return low;
    }

	int partition4(vector<int> &v, int start, int end)
	{
		int idx = start + (random() % (end - start + 1));
		swap(v[idx], v[end]); // swap pivot element to end
		int pivot = start;

		for (int i = start; i < end; i++) {
			if (v[i] < v[end]) {
				swap(v[pivot++], v[i]);
			}
		}

		swap(v[pivot], v[end]);
		return pivot;
	}

    void sort(vector<int> &v, int start, int end)
    {
        if (start < end) {
            int pivot = partition(v, start, end);
            sort(v, start, pivot - 1);
            sort(v, pivot + 1, end);
        }
    }

public:
    void sort(vector<int> &v)
    {
        size_t len = v.size();
        if (len <= 1) return;

        srand(time(nullptr));
        sort(v, 0, len - 1);
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

    QuickSort obj;

    print_vec(v);
    obj.sort(v);
    print_vec(v);

    return 0;
}
