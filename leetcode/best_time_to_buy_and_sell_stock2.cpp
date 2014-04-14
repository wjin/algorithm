/*

 Best Time to Buy and Sell Stock II

 Say you have an array for which the ith element is the price of a given stock on day i.

 Design an algorithm to find the maximum profit. You may complete as many transactions
 as you like (ie, buy one and sell one share of the stock multiple times).
 However, you may not engage in multiple transactions at the same time
 (ie, you must sell the stock before you buy again).

 */

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // actually, it equals to calculate sum of all increasing line segment
    int maxProfit(vector<int> &prices)
    {
        int len = prices.size();
        if (len < 2)
            return 0;

        int ret = 0;
        int i;
        for (i = 1; i < len; ++i) {
            if (prices[i] > prices[i - 1]) {
                ret += prices[i] - prices[i - 1];
            }
        }

        return ret;
    }
};

int main(int argc, char *argv[])
{
    vector<int> v = { 1, 2, 6, 3, 9 };
    Solution sol;

    cout << sol.maxProfit(v) << endl;

    return 0;
}
