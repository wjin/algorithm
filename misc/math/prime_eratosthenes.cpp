#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

using namespace std;

// generate prime number
// Eratosthenes algorithm
class Solution
{
private:
    int maxNum;
    vector<bool> v;

    void initialize()
    {
        int root = sqrt(maxNum);

        v[0] = v[1] = false;
        for (int i = 2; i <= root; i++) { // =
            if (v[i]) {
                for (int j = 2; j * i <= maxNum; j++) {
                    v[j * i] = false;
                }
            }
        }
    }

public:
    Solution(const int n = 30000) : maxNum(n), v(maxNum + 1, true)
    {
        initialize();
    }

    bool isPrime(int n)
    {
        if (n > maxNum) {
            maxNum = (n << 1); // simply double n
            v.resize(maxNum + 1, true);
            initialize();
        }
        return v[n];
    }

    int getNthPrime(int n)
    {
        while (true) {
            int cnt = 0;
            for (size_t i = 2; i < v.size(); i++) {
                if (v[i]) cnt++;
                if (cnt == n) return i;
            }

            // calculate more primes, simply doulbe it
            maxNum <<= 1;
            v.resize(maxNum + 1, true);
            initialize();
        }
    }
};

int main(int argc, char* argv[])
{
    Solution sol(9);

    cout << sol.getNthPrime(1) << endl;
    cout << sol.getNthPrime(2) << endl;
    cout << sol.getNthPrime(3) << endl;
    cout << sol.getNthPrime(4) << endl;
    cout << sol.getNthPrime(5) << endl;

    cout << sol.isPrime(13) << endl;
    cout << sol.isPrime(100) << endl;

    return 0;
}
