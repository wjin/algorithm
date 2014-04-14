/*
 * judge stack pop order
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
public:
    // both orders have no duplicate numbers
    bool isPopOrder(vector<int> &push, vector<int> &pop)
    {
        size_t pushLen = push.size(), popLen = pop.size();

        if (pushLen == 0 && popLen == 0) return true;
        if (pushLen != popLen) return false;

        stack<int> stk;
        size_t idxPush = 0, idxPop = 0;

        while (idxPush < pushLen) { // stop condition
            // each cycle, push one number to stack
            if (stk.empty() || stk.top() != pop[idxPop]) {
                stk.push(push[idxPush++]);
            }

            // pop stack as many as possible
            while (!stk.empty() && (stk.top() == pop[idxPop])) {
                stk.pop();
                idxPop++;
            }
        }

        return stk.empty();
    }
};

int main(int argc, char *argv[])
{
    vector<int> push = { 1, 2, 3, 4, 5 };
    vector<int> pop1 = { 4, 5, 3, 2, 1 };
    vector<int> pop2 = { 4, 3, 5, 1, 2 };

    Solution sol;

    cout << sol.isPopOrder(push, pop1) << endl;
    cout << sol.isPopOrder(push, pop2) << endl;

    return 0;
}
