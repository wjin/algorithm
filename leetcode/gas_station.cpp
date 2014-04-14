
/*

 Gas Station

 There are N gas stations along a circular route, where the
 amount of gas at station i is gas[i].

 You have a car with an unlimited gas tank and it costs cost[i]
 of gas to travel from station i to its next station (i+1).
 You begin the journey with an empty tank at one of the gas stations.

 Return the starting gas station's index if you can travel around
 the circuit once, otherwise return -1.

 Note:
 The solution is guaranteed to be unique.

 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int numOfStation = gas.size();
        if (numOfStation == 0)
            return -1;
        /*
         * cannot pass OJ here, see test case three
         * however, I don't think it is reasonable because
         * if there is only one station, how should we travel around?

        else if (numOfStation == 1)
        	return 0;
        */

        vector<int> gap;
        for (int i = 0; i < numOfStation; i++) {
            gap.push_back(gas[i] - cost[i]);
        }

        int start = 0, end = 0, sum = 0, tmp = 0;
        do {
            tmp = sum + gap[end];
            if (tmp >= 0) {
                end = (end + 1) % numOfStation;  // go ahead, end++
                sum = tmp;
            } else {
                // start--, to find a new start point
                start = (start - 1 + numOfStation) % numOfStation;
                sum += gap[start];
            }
        } while (start != end);

        return sum >= 0 ? start : -1;
    }

    int canCompleteCircuit2(vector<int> &gas, vector<int> &cost)
    {
        int total = 0, sum = 0;
        int start = -1;
        for (size_t i = 0; i < gas.size(); i++) {
            total += gas[i] - cost[i];
            sum += gas[i] - cost[i];

            if (sum < 0) {
                sum = 0;
                start = i;
            }
        }

        return total >= 0 ? start + 1 : -1;  // =
    }
};

int main(int argc, char* argv[])
{
    Solution sol;
    vector<int> gas1 = { 1, 0 };
    vector<int> cost1 = { 1, 1 };

    vector<int> gas2 = { 1, 1, 2 };
    vector<int> cost2 = { 1, 2, 1 };

    vector<int> gas3 = { 4 };
    vector<int> cost3 = { 5 };

    cout << sol.canCompleteCircuit(gas1, cost1) << endl;
    cout << sol.canCompleteCircuit(gas2, cost2) << endl;
    cout << sol.canCompleteCircuit(gas3, cost3) << endl;

    cout << sol.canCompleteCircuit2(gas1, cost1) << endl;
    cout << sol.canCompleteCircuit2(gas2, cost2) << endl;
    cout << sol.canCompleteCircuit2(gas3, cost3) << endl;

    return 0;
}
