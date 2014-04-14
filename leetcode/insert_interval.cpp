/*
   Insert Interval

   Given a set of non-overlapping intervals, insert a new interval
   into the intervals (merge if necessary).

   You may assume that the intervals were initially sorted
   according to their start times.

   Example 1:
   Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

   Example 2:
   Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and
   merge [4,9] in as [1,2],[3,10],[12,16].

   This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].

*/

#include <iostream>
#include <vector>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution
{
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval)
    {
        if (intervals.empty()) { // may be removed this if
            intervals.push_back(newInterval);
            return intervals;
        }

        auto ite = intervals.begin();
        while (ite != intervals.end()) {
            if (ite->start > newInterval.end) {  // insert and return, no need to merge
                intervals.insert(ite, newInterval);
                return intervals;
            } else if (ite->end < newInterval.start) { // find propert position to insert
                ite++;
            } else { // delete merged item and update insert item
                newInterval.start = min(ite->start, newInterval.start);
                newInterval.end = max(ite->end, newInterval.end);
                ite = intervals.erase(ite);
            }
        }

        // we merged to the last element
        intervals.push_back(newInterval);
        return intervals;
    }
};

void print_vector(vector<Interval> &v)
{
    for (auto e : v) {
        cout << e.start << " " << e.end << endl;
    }
}

int main(int argc, char *argv[])
{
    Solution sol;

    vector<Interval> v1;
    v1.push_back(Interval(1, 3));
    v1.push_back(Interval(6, 9));

    sol.insert(v1, Interval(2, 5));
    print_vector(v1);

    vector<Interval> v2;
    v2.push_back(Interval(1, 2));
    v2.push_back(Interval(3, 5));
    v2.push_back(Interval(6, 7));
    v2.push_back(Interval(8, 10));
    v2.push_back(Interval(12, 16));

    sol.insert(v2, Interval(4, 9));
    print_vector(v2);

    return 0;

}
