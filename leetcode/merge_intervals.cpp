/*

   Merge Intervals

   Given a collection of intervals, merge all overlapping intervals.

   For example,
   Given [1,3],[2,6],[8,10],[15,18],
   return [1,6],[8,10],[15,18].

*/

#include <iostream>
#include <vector>
#include <algorithm>

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

    vector<Interval> merge(vector<Interval> &intervals)
    {
        vector<Interval> ret;
        for (auto e : intervals)
            ret = insert(ret, e);
        return ret;
    }
};

class Solution2
{
private:
    static bool comp(const Interval &lht, const Interval &rht)
    {
        return lht.start < rht.start;
    }
public:
    vector<Interval> merge(vector<Interval> &intervals)
    {
        if (intervals.size() <= 1) return intervals;
        vector<Interval> ret;
        sort(intervals.begin(), intervals.end(), comp);

        ret.push_back(intervals[0]);
        for (size_t i = 1; i < intervals.size(); i++) {
            if (ret.back().end < intervals[i].start) {
                ret.push_back(intervals[i]);
            } else { // merge
                ret.back().end = max(ret.back().end, intervals[i].end);
            }
        }

        return ret;
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
    v1.push_back(Interval(2, 6));
    v1.push_back(Interval(8, 10));
    v1.push_back(Interval(15, 18));

    vector<Interval> ret = sol.merge(v1);
    print_vector(ret);

    return 0;

}
