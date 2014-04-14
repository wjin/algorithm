#include <iostream>

using namespace std;

// solution 1
// founction pointer
typedef int (*Func)(int); // function poniter type
int f1(int);  // declaration first
int f2(int);
Func f[2] = {f1, f2};

int f1(int n)
{
    return 0;
}

int f2(int n)
{
    return n + f[!!n](n - 1);
}

// solution 2
// construction function
class Solution
{
    static unsigned int n; // static
    static unsigned int sum;
public:
    Solution()
    {
        n++;
        sum += n;
    }

    static unsigned int getSum() // static function
    {
        return sum;
    }
};
unsigned int Solution::n = 0; // no static
unsigned int Solution::sum = 0;

// solution 3
// template
template <unsigned int n>
struct Solution2 {
    enum Value { N = Solution2<n - 1> :: N + n};
};

// template specialization
template <>
struct Solution2<1> {
    enum Value { N = 1};
};

int main(int argc, char *argv[])
{
    const int n = 10;
    cout << f2(n) << endl;

    Solution *tmp = new Solution[n];
    delete tmp;
    cout << Solution::getSum() << endl;

    cout << Solution2<n>::N << endl; // n must be const here

    return 0;
}
