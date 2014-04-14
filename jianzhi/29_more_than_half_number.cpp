#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int moreThanHalf(vector<int> &num)
    {
        int len = num.size();
        if (len <= 0) return -1; // invalid

        int cnt = 0, ret = -1;
        for (int i = 0; i < len; i++) {
            if (cnt == 0) {
                cnt++;
                ret = num[i];
            } else if (ret == num[i]) {
                cnt++;
            } else {
                cnt--;
            }
        }

        if (count(num.begin(), num.end(), ret) > (signed)(num.size() / 2)) return ret;
        return -1;
    }
};

class Solution2
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
        int rand = getRandom(start, end);
        int pivot = num[rand];
        swap(num[rand], num[end]);
        int origEnd = end;
        end--;

        while (start < end) {
            if (num[start] <= pivot) start++;
            else if (num[end] > pivot) end--;
            else {
                swap(num[start], num[end]);
            }
        }

        swap(num[start], num[origEnd]);
        return start;
    }

public:
    int moreThanHalf(vector<int> &num)
    {
        int len = num.size();
        int start = 0, end = len - 1;
        int mid = len / 2;
        int idx = partition(num, 0, end);

        while (idx != mid) {
            if (idx > mid) {
                end = idx - 1;
            } else {
                start = idx + 1;
            }
            idx = partition(num, start, end);
        }

        if (count(num.begin(), num.end(), num[idx]) > mid) return num[idx];
        return -1;
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
    Solution sol;
    Solution2 sol2;
    vector<int> num = { 1, 2, 3, 2, 2, 2, 5, 4, 2 };
    vector<int> num2 = { 1, 1, 2, 3, 2, 2, 2, 5, 4, 2 };

    print_vector(num);
    cout << sol.moreThanHalf(num) << endl;
    print_vector(num);
    cout << sol2.moreThanHalf(num) << endl;
    print_vector(num);

    print_vector(num2);
    cout << sol.moreThanHalf(num2) << endl;
    print_vector(num2);
    cout << sol2.moreThanHalf(num2) << endl;
    print_vector(num2);

    return 0;
}
