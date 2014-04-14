/*

 Best Time to Buy and Sell Stock  III

 Say you have an array for which the ith element is the price of a given stock on day i.

 Design an algorithm to find the maximum profit. You may complete at most two transactions.

 Note:
 You may not engage in multiple transactions at the same time
 (ie, you must sell the stock before you buy again).

 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    // cut  array into two parts. for each part, we can calculate its max respectively.
    // max_profit = max (max(prices[0...i]) + max(prices[i+1...n-1])), i from 0 to n-1

    // use dp to accelerate calculation
    int maxProfit(vector<int> &prices)
    {
        int len = prices.size();
        if (len <= 1)
            return 0;

        vector<int> lMax(len + 1, 0);
        int min_element = prices[0];
        lMax[0] = 0;

        // calculate max left profit ending with i, 0...i
        for (int i = 1; i <= len; i++) {
            min_element = min(min_element, prices[i - 1]);
            lMax[i] = max(lMax[i - 1], prices[i - 1] - min_element);
        }

        // calculate max right profit starting with i, i...n-1
        // and meantime calculate max profit
        int max_profit = 0;
        int rMax = 0;
        int max_element = prices[len - 1];
        for (int i = len; i >= 1; i--) {
            max_element = max(max_element, prices[i - 1]);
            rMax = max_element - prices[i - 1]; // max profit of element i...n-1
            max_profit = max(max_profit, lMax[i - 1] + rMax);
        }

        return max_profit;
    }
};

int main(int argc, char *argv[])
{
    vector<int> v1 = { 1, 2, 6, 3, 9, 2, 1, 10 };
    vector<int> v2 = { 1, 2, 4, 2, 5, 7, 2, 4, 9, 0 }; // be careful
    vector<int> v3 = { 1, 2 }; // be careful

    Solution sol;
    cout << sol.maxProfit(v1) << endl;
    cout << sol.maxProfit(v2) << endl;
    cout << sol.maxProfit(v3) << endl;

    return 0;
}
