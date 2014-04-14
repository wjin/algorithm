/*

 Candy

 There are N children standing in a line. Each child is assigned a rating value.
 You are giving candies to these children subjected to the following requirements:

 Each child must have at least one candy.
 Children with a higher rating get more candies than their neighbors.

 What is the minimum candies you must give?

 */

#include <iostream>
#include <vector>
#include <numeric> // accumulate

using namespace std;

class Solution
{
public:
    // greedy algorithm
    int candy(vector<int> &ratings)
    {
        int numOfChild = ratings.size();
        vector<int> candyNum(numOfChild, 1);

        // left to right
        for (int i = 1; i < numOfChild; i++) {
            if (ratings[i] > ratings[i - 1])
                candyNum[i] = candyNum[i - 1] + 1;
        }

        // right to left
        for (int i = numOfChild - 1; i > 0; i--) {
            if (ratings[i - 1] > ratings[i]) {
                if (candyNum[i - 1] <= candyNum[i])  // judge
                    candyNum[i - 1] = candyNum[i] + 1;
            }
        }

        return accumulate(candyNum.begin(), candyNum.end(), 0);
    }
};

int main(int argc, char* argv[])
{
    Solution sol;
    vector<int> ratings1 = { 1, 1, 1 };
    vector<int> ratings2 = { 1, 2, 2, 2 };
    vector<int> ratings3 = { 1, 2, 3, 4, 1, 1 };

    cout << sol.candy(ratings1) << endl;
    cout << sol.candy(ratings2) << endl;
    cout << sol.candy(ratings3) << endl;

    return 0;
}
