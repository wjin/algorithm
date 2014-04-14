#include <iostream>

using namespace std;

void print_begin_to_end(int begin, int end)
{
    for (int k = begin; k <= end; k++)
        cout << k << ' ';
    cout << endl;
}

void consecutive_sum_n(int n)
{
    if (n < 3) return;

    int begin = 1, end = 2;
    int sum = begin + end;
    int stop = (n + 1) / 2;

    while (begin < stop) {
        if (sum == n)
            print_begin_to_end(begin, end);

        if (sum > n) {
            sum -= begin;
            begin++;
        } else { // sum <= n
            end++;
            sum += end;
        }
    }
}

int main(int argc, char *argv[])
{
    consecutive_sum_n(9);
    consecutive_sum_n(15);

    return 0;
}
