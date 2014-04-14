/*

 Best Time to Buy and Sell Stock

 Say you have an array for which the ith element is the price of a given stock on day i.

 If you were only permitted to complete at most one transaction (ie, buy one and sell one
 share of the stock), design an algorithm to find the maximum profit.

 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int max_profit = 0;
        int min_ele = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < min_ele)
                min_ele = prices[i];
            else {
                max_profit = max(max_profit, prices[i] - min_ele);
            }
        }
        return max_profit;
    }
};

int main(int argc, char *argv[])
{
    vector<int> v = { 1, 2, 6, 3, 9 };
    Solution sol;

    cout << sol.maxProfit(v) << endl;
    return 0;
}

