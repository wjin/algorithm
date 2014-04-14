/*
 * binary search problem summary
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1) book: beauty of programming  (p261)
// 2) search in a rotated sorted array (duplicate, leetcode)
// 3) search the minimum number in  a rotated sorted array (jianzhi)

// 1)
class BinarySearch
{
private:
    vector<int> m_data;
public:
    BinarySearch(vector<int> &v) :
        m_data(v)
    {
    }

    void output_data()
    {
        for (auto t : m_data)
            cout << t << ends;
        cout << endl;
    }

    // general binary search algorithm
    // return any pos such that m_data[i] == target
    int general_search(int target)
    {
        int low = 0, high = m_data.size() - 1;
        int mid = 0;
        while (low <= high) { // =
            mid = low + ((high - low) >> 1); // be careful about overflow
            if (m_data[mid] == target)
                return mid;
            else if (m_data[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }

    // lower_bound
    // return max pos such that m_data[i] == target
    int search_return_max_pos(int target)
    {
        int low = 0, high = m_data.size() - 1;
        int mid = 0;
        while (low <= high) { // =
            mid = low + ((high - low) >> 1); // be careful about overflow
            if (m_data[mid] == target) {
                if (m_data[high] == target) // judge it here
                    return high;
                else { // update search bound
                    low = mid;
                    high -= 1;
                }
            } else if (m_data[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }

    // upper_bound - 1
    // return min pos such that m_data[i] == target
    int search_return_min_pos(int target)
    {
        int low = 0, high = m_data.size() - 1;
        int mid = 0;
        while (low <= high) { // =
            mid = low + ((high - low) >> 1); // be careful about overflow
            if (m_data[mid] == target) {
                if (m_data[low] == target)
                    return low;
                else { // update search bound
                    low += 1;
                    high = mid;
                }
            } else if (m_data[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }

    // return max pos such that m_data[i] < target
    int search_maxpos_less_than_target(int target)
    {
        int low = 0, high = m_data.size() - 1;
        int mid = 0;
        int lowest = low; // used to avoid mid - 1 out of bound

        while (low <= high) { // =
            mid = low + ((high - low) >> 1); // be careful about overflow
            if (m_data[mid] == target) {
                if (mid == lowest) return -1; // bug
                if (m_data[mid - 1] < target)
                    return mid - 1;
                else
                    high = mid - 1; // m_data[mid - 1] == target
            } else if (m_data[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }

    // return min pos such that m_data[i] > target
    int search_minpos_greater_than_target(int target)
    {
        int low = 0, high = m_data.size() - 1;
        int mid = 0;
        int highest = high; // used to avoid mid + 1 out of bound
        while (low <= high) { // =
            mid = low + ((high - low) >> 1); // be careful about overflow
            if (m_data[mid] == target) {
                if (mid == highest) return -1; // bug
                if (m_data[mid + 1] > target)
                    return mid + 1;
                else
                    low = mid + 1; // m_data[mid + 1] == target
            } else if (m_data[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return -1;
    }

    void do_search(int target)
    {
        output_data();
        cout << general_search(target) << endl;
        cout << search_return_max_pos(target) << endl;
        cout << search_return_min_pos(target) << endl;
        cout << search_maxpos_less_than_target(target) << endl;
        cout << search_minpos_greater_than_target(target) << endl;
        cout << endl;
    }
};

int main(int argc, char *argv[])
{
    vector<int> v;
    v.resize(10);

    // vector with strict ascending data
    iota(v.begin(), v.end(), 1);
    BinarySearch bs(v);
    int target;

    target = 0;
    bs.do_search(target);

    target = 1;
    bs.do_search(target);

    target = 5;
    bs.do_search(target);

    target = 10;
    bs.do_search(target);

    target = 11;
    bs.do_search(target);

    // non descending order
    fill(v.begin(), v.end(), 5);
    bs = BinarySearch(v);

    target = 0;
    bs.do_search(target);

    target = 5;
    bs.do_search(target);

    target = 10;
    bs.do_search(target);

    return 0;
}
