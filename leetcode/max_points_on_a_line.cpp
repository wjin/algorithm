/*

   Max Points on a Line

   Given n points on a 2D plane, find the maximum number
   of points that lie on the same straight line.

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
#include <algorithm>

using namespace std;

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution
{
public:
    int maxPoints(vector<Point> &points)
    {
        int len = points.size();
        if (len < 3) return points.size();

        int maxPoint = 0;
        int samePoint = 0;
        double slope = 0; // double
        unordered_map<double, int> slopeCnt;
        int curSlopeMax = 0;
        for (int i = 0; i < len - 1; i++) {
            samePoint = 1; // be careful
            curSlopeMax = 0;
            slopeCnt.clear();
            for (int j = i + 1; j < len; j++) {
                if (points[i].x == points[j].x && // duplicate point
                        points[i].y == points[j].y) {
                    samePoint++;
                    continue;
                }

                // calculate slope
                if (points[i].x == points[j].x) { // vertical x axis
                    slope = numeric_limits<double>::infinity();
                } else {
                    // double type conversion
                    slope = (double)(points[j].y - points[i].y) / (points[j].x - points[i].x);
                }

                // count current slope max number with point i
                // however, point i is not included in the hash value
                // it will be included in samePoint
                slopeCnt[slope]++;
                curSlopeMax = max(curSlopeMax, slopeCnt[slope]);
            }

            maxPoint = max(maxPoint, curSlopeMax + samePoint);
        }
        return maxPoint;
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    Point p11(0, 0), p12(1, 1), p13(0, 0); // bug
    Point p21(1, 1), p22(1, 1), p23(1, 1); // bug
    Point p31(1, 1), p32(2, 2), p33(3, 3);
    Point p41(84,250), p42(0,0), p43(1,0), p44(0,-70), p45(0,-70),
          p46(1,-1), p47(21,10),p48(42,90), p49(-42,-230); // miss double type conversion when calculate slope

    vector<Point> points1 = {p11, p12, p13};
    vector<Point> points2 = {p21, p22, p23};
    vector<Point> points3 = {p31, p32, p33};
    vector<Point> points4 = {p41, p42, p43, p44, p45, p46, p47, p48, p49};

    cout << sol.maxPoints(points1) << endl;
    cout << sol.maxPoints(points2) << endl;
    cout << sol.maxPoints(points3) << endl;
    cout << sol.maxPoints(points4) << endl;

    return 0;
}
