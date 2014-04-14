/*

 Next Permutation

 Implement next permutation, which rearranges numbers into
 the lexicographically next greater permutation of numbers.

 If such arrangement is not possible, it must rearrange it
 as the lowest possible order (ie, sorted in ascending order).

 The replacement must be in-place, do not allocate extra memory.

 Here are some examples. Inputs are in the left-hand column and
 its corresponding outputs are in the right-hand column.

 1,2,3 → 1,3,2
 3,2,1 → 1,2,3
 1,1,5 → 1,5,1

 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*

 Step 1: Find the largest index k, such that A[k] < A[k+1].
 If not exist, this is the last permutation.
 just reverse the vector to get the first permutation
 Step 2: Find the largest index l, such that A[l] > A[k].
 Step 3: Swap A[k] and A[l].
 Step 4: Reverse A[k+1] to the end

 */
class Solution
{
public:
    void nextPermutation(vector<int> &num)
    {
        int k = num.size() - 2;
        while (k >= 0) { // step 1
            if (num[k] < num[k + 1])
                break;
            k--;
        }
        if (k < 0) {
            reverse(num.begin(), num.end());
            return;
        }

        int l = num.size() - 1;
        while (l > k) { // step 2
            if (num[l] > num[k])
                break;
            l--;
        }

        swap(num[k], num[l]); // step 3
        reverse(num.begin() + k + 1, num.end()); // step 4
    }
};

int main(int argc, char *argv[])
{
    Solution sol;
    vector<int> v = { 1, 2, 3 };

    int k = 7;
    while (k--) {
        for (auto t : v)
            cout << t << ends;
        cout << endl;

        sol.nextPermutation(v);
    }

    return 0;
}
