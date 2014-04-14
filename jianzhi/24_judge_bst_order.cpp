/*
 * judge BST pre/post order
 */

#include <iostream>
#include <vector>

using namespace std;

class PostOrderSolution
{
private:
    bool isBSTPostOrder(vector<int> &seq, int start, int end)
    {
        if (start >= end) return true; // >

        int root = seq[end];

        // find left child end
        // also left child might be null
        int i = start;
        while (i <= end && seq[i] < root) {
            i++;
        }

        // judge all right child nodes are greater than root
        int j = i;
        while (j < end && seq[j] > root) {
            j++;
        }
        if (j != end) return false;

        return isBSTPostOrder(seq, start, i - 1) &&
               isBSTPostOrder(seq, i, end -1);
    }

public:
    // sequence has no duplicate numbers
    bool isBSTPostOrder(vector<int> &sequence)
    {
        int len = sequence.size();
        if (len <= 1) return true;
        return isBSTPostOrder(sequence, 0, len - 1);
    }
};

class PreOrderSolution
{
private:
    bool isBSTPreOrder(vector<int> &seq, int start, int end)
    {
        if (start >= end) return true; // >

        int root = seq[start];

        // find left child end
        // also left child might be null
        int i = start + 1;
        while (i <= end && seq[i] < root) {
            i++;
        }

        // judge all right child nodes are greater than root
        int j = i;
        while (j <= end && seq[j] > root) {
            j++;
        }
        if (j != end + 1) return false;

        return isBSTPreOrder(seq, start + 1, i - 1) &&
               isBSTPreOrder(seq, i, end);
    }

public:
    // sequence has no duplicate numbers
    bool isBSTPreOrder(vector<int> &sequence)
    {
        int len = sequence.size();
        if (len <= 1) return true;
        return isBSTPreOrder(sequence, 0, len - 1);
    }
};

void test_post()
{
    vector<int> sequence1 = { 5, 7, 6, 9, 11, 10, 8 };
    vector<int> sequence2 = { 7, 4,  6, 5 };
    vector<int> sequence3 = { 1, 2, 3 };
    vector<int> sequence4 = { 3, 2, 1 };

    PostOrderSolution sol;

    cout << sol.isBSTPostOrder(sequence1) << endl;
    cout << sol.isBSTPostOrder(sequence2) << endl;
    cout << sol.isBSTPostOrder(sequence3) << endl;
    cout << sol.isBSTPostOrder(sequence4) << endl;
}

void test_pre()
{
    vector<int> sequence1 = { 5, 7, 6, 9, 11, 10, 8 }; // 0
    vector<int> sequence2 = { 7, 4,  6, 5 }; // 1
    vector<int> sequence3 = { 1, 2, 3 };
    vector<int> sequence4 = { 3, 2, 1 };

    PreOrderSolution sol;

    cout << sol.isBSTPreOrder(sequence1) << endl;
    cout << sol.isBSTPreOrder(sequence2) << endl;
    cout << sol.isBSTPreOrder(sequence3) << endl;
    cout << sol.isBSTPreOrder(sequence4) << endl;
}

int main(int argc, char *argv[])
{
    test_post();
    test_pre();

    return 0;
}
