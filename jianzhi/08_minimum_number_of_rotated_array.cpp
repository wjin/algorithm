#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// find minimum of rotated sorted array
class Solution
{
public:
    int minimum_of_rotated_sorted_array(const vector<int> &v)
    {
        int len = v.size();
        if (len == 0) throw runtime_error("invalid input"); // invalid
        if (len == 1) return v[0];

        int low = 0, high = len - 1;
        if (v[low] < v[high]) return v[low]; // rotate entire array, back to original array

        while (v[low] >= v[high]) {
            if (low + 1 == high) return v[high]; // be careful

            int mid = low + (high - low) / 2;

            if (v[low] == v[mid] && v[mid] == v[high]) { // special case, cannot judge, linear search
                return *min_element(v.begin() + low, v.begin() + high + 1);
            }

            if (v[low] <= v[mid]) { // first half is ascending
                low = mid;
            } else {
                high = mid;
            }
        }
        // return v[high];
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v1 = {1};
    vector<int> v2 = {1, 2, 3, 4, 5};
    vector<int> v3 = {3, 4, 5, 1, 2};
    vector<int> v4 = {1, 0, 1, 1, 1};
    vector<int> v5 = {1, 1, 1, 0, 1};
    vector<int> v6 = {1, 1, 1, 0, 1, 1, 1, 1, 1};

    cout << sol.minimum_of_rotated_sorted_array(v1) << endl;
    cout << sol.minimum_of_rotated_sorted_array(v2) << endl;
    cout << sol.minimum_of_rotated_sorted_array(v3) << endl;
    cout << sol.minimum_of_rotated_sorted_array(v4) << endl;
    cout << sol.minimum_of_rotated_sorted_array(v5) << endl;
    cout << sol.minimum_of_rotated_sorted_array(v6) << endl;
    // cout << sol.minimum_of_rotated_sorted_array(vector<int>()) << endl;

    return 0;
}
