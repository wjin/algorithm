/*

 Maximum Subarray

 Find the contiguous subarray within an array (containing at least one number)
 which has the largest sum.

 For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 the contiguous subarray [4,−1,2,1] has the largest sum = 6.

 More practice:
 If you have figured out the O(n) solution, try coding another solution
 using the divide and conquer approach, which is more subtle.

 */

#include <iostream>
#include <climits>
#include <initializer_list>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int maxSubArray(int A[], int n)
    {
        int max_sum = INT_MIN;
        int interimSum = INT_MIN; // interim sum ending with array element i

        // dp
        for (int i = 0; i < n; i++) {
            if (interimSum <= 0)
                interimSum = A[i];
            else
                interimSum += A[i];

            // max sum is the max of all interimSums
            max_sum = max(interimSum, max_sum);
        }

        return max_sum;
    }
};

// divide and conquer
// three cases:
//   1) max is on the left
//   2) max is on the right
//   3) max includes middle element
class Solution2
{
public:
    int divideAndConquer(int A[], int i, int j)
    {
        if (i == j)
            return A[i];
        else if (i == j - 1)
            return max( { A[i], A[j], A[i] + A[j] }); // do not forget A[i] + A[j]
        else {
            int mid = i + (j - i) / 2;
            int lMax = divideAndConquer(A, i, mid - 1);  // left max
            int rMax = divideAndConquer(A, mid + 1, j); // right max

            int leftSum = 0;
            int leftMax = INT_MIN;
            for (int k = mid - 1; k >= i; k--) {
                leftSum += A[k];
                leftMax = max(leftMax, leftSum);
            }

            int rightSum = 0;
            int rightMax = INT_MIN;
            for (int k = mid + 1; k <= j; k++) {
                rightSum += A[k];
                rightMax = max(rightMax, rightSum);
            }

            // leftMax and rightMax may be both little than 0
            // or just one of them is little than 0
            // we should not accumulate negative number to max
            int mMax = A[mid]; // middle max, at least include the middle element
            mMax += leftMax > 0 ? leftMax : 0;
            mMax += rightMax > 0 ? rightMax : 0;

            return max( { lMax, rMax, mMax });
        }
    }

    int maxSubArray(int A[], int n)
    {
        if (n == 0)
            return 0;
        else {
            return divideAndConquer(A, 0, n - 1);
        }
    }
};

int main(int argc, char *argv[])
{
    int array[] = { -1, 1, -3, 4, -1, 2, 1, -5, 4 };
    int array2[] = { -1, 0, -2 };
    int array3[] = { 1, 2, -1 };

    Solution sol;
    cout << sol.maxSubArray(array, sizeof(array) / sizeof(int)) << endl;
    cout << sol.maxSubArray(array2, sizeof(array2) / sizeof(int)) << endl;
    cout << sol.maxSubArray(array3, sizeof(array3) / sizeof(int)) << endl;

    Solution2 sol2;
    cout << sol2.maxSubArray(array, sizeof(array) / sizeof(int)) << endl;
    cout << sol2.maxSubArray(array2, sizeof(array2) / sizeof(int)) << endl;
    cout << sol2.maxSubArray(array3, sizeof(array3) / sizeof(int)) << endl;

    return 0;
}
