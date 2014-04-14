/*

 Gray Code

 The gray code is a binary numeral system where two successive values differ in only one bit.

 Given a non-negative integer n representing the total number of bits in the code,
 print the sequence of gray code. A gray code sequence must begin with 0.

 For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

 00 - 0
 01 - 1
 11 - 3
 10 - 2

 Note:
 For a given n, a gray code sequence is not uniquely defined.

 For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

 For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.

 */

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

/*

 In the construction of Gray codes, sequences of binary values with the property that
 consecutive sequence values differ from each other in a single bit position, a number n
 can be converted into the Gray code value at position n of the sequence simply by taking
 the exclusive or of n and n/2 (the number formed by shifting n right by a single bit position).

 The reverse operation, decoding a Gray-coded value x into a binary number, is more complicated,
 but can be expressed as the prefix sum of the bits of x, where each summation operation within the
 prefix sum is performed modulo two. A prefix sum of this type may be performed efficiently using the
 bitwise Boolean operations available on modern computers, by computing the exclusive or of x with each
 of the numbers formed by shifting x to the left by a number of bits that is a power of two.

 // n = n ^ (n/2)
 unsigned int binaryToGray(unsigned int num)
 {
         return (num >> 1) ^ num;
 }

 // prefix sum
 unsigned int grayToBinary(unsigned int num)
 {
	    unsigned int mask;
		for (mask = num >> 1; mask != 0; mask = mask >> 1)
		{
			num = num ^ mask;
		}
		return num;
 }

 */

class Solution
{
public:
    // http://en.wikipedia.org/wiki/Gray_code

    // The binary-reflected Gray code list for n bits can be generated recursively
    // from the list for n-1 bits by reflecting the list (i.e. listing the entries
    // in reverse order), concatenating the original list with the reversed list,
    // prefixing the entries in the original list with a binary 0, and then
    // prefixing the entries in the reflected list with a binary 1.
    vector<int> grayCode(int n)
    {
        if (n < 0) // error input
            return vector<int>();
        else if (n == 0) // online judge require it
            return vector<int>(1, 0);
        else if (n == 1)
            return vector<int>( { 0, 1 });
        else {
            vector<int> ret = grayCode(n - 1);
            for (int i = ret.size() - 1; i >= 0; i--)
                ret.push_back((1 << (n - 1)) | ret[i]);

            return ret;
        }
    }

    vector<int> grayCode2(int n)
    {
        vector<int> ret;
        int size = 1 << n; // total number: 0...2^n -1
        for (int i = 0; i < size; ++i)
            ret.push_back((i >> 1) ^ i);
        return ret;
    }
};

int main(int argc, char *argv[])
{
    int n = 3;
    Solution sol;

    vector<int> ret = sol.grayCode2(n);

    for (auto t : ret)
        cout << t << ends;

    return 0;
}
