/*
 * rotate element...
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
  rotate elements [first, last) such that element pos becomes
  the first element like this: pos...last-1 first...pos-1
 */

/*
  1) first solution:
     a) reverse [first, pos)
     b) reverse [pos, last)
     c) reverse [first, last)

  2) second solution:
     time complexity : O(n)
     space complexity: O(1)
*/
template<typename T>
void myRotate(T first, T pos, T last)
{
    T next = pos;
    while (first != next) {
        swap(*first++, *next++);
        if (next == last) {
            next = pos;
        } else if (first == pos) {
            pos = next;
        }
    }
}

int main(int argc, char *argv[])
{
    // test builtin array
    int array [5] = {1, 2, 3, 4, 5};
    myRotate(array, array + 3, array + 5);
    for (auto e : array)
        cout << e << ' ';
    cout << endl;

    // test vector
    vector<int> v = { 1, 2 , 3, 4, 5};
    myRotate(v.begin(), v.begin() + 3, v.end());
    for (auto e : v)
        cout << e << ' ';
    cout << endl;

    // test string
    string s("12345");
    myRotate(s.begin(), s.begin() + 3, s.end());
    cout << s << endl;

    return 0;
}
