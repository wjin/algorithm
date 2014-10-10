#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution
{
private:
    const int diceMaxValue = 6;

    vector<int> timeForEachSum(int n)
    {
        const int maxSum = diceMaxValue * n;
        vector<int> time(maxSum + 1, 0), tmp(maxSum + 1, 0); // zero not used

        // init for one dice
        for (int diceValue = 1; diceValue <= diceMaxValue; diceValue++) {
            time[diceValue] = 1;
        }

        // add dices one by one to calculate
        // for time[idx], it might be:
        // time[idx] = time[idx-1]+time[idx-2]+...+time[idx-6]
        for (int numOfDice = 2; numOfDice <= n; numOfDice++) {
            for (int idx = numOfDice; idx <= diceMaxValue * numOfDice; idx++) {
                for (int k = 1; k <= diceMaxValue && k <= idx; k++) {
                    tmp[idx] += time[idx - k];
                }
            }

            swap(time, tmp);
            fill(tmp.begin(), tmp.end(), 0);
        }

        return time;
    }

    vector<double> getRatio(vector<int> &times, int n)
    {
        vector<double> ret;
        double total = pow(diceMaxValue, n);

        for (auto e : times) {
            ret.push_back(e / total);
        }

        return ret;
    }

public:
    vector<double> probability(int n)
    {
        vector<int> times = timeForEachSum(n);
        return getRatio(times, n);
    }
};

void dump(vector<double> &v)
{
    double probability = 0;
    for (auto e : v) {
        cout << e << ' ';
        probability += e;
    }
    cout << endl;
    cout << "Probability: " << probability << endl;
}

int main(int argc, char *argv[])
{
    Solution sol;
    vector<double> ret;

    for (int i = 1; i < 10; i++) {
        ret = sol.probability(i);
        cout << "Result" << i << ": ";
        dump(ret);
    }

    return 0;
}
