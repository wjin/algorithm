/*

5.8

A monochrome screen is stored as a single array of bytes, allowing eight consecutive
pixels to be stored in one byte. The screen has width w, where w is divisible
by 8 (that is, no byte will be split across rows). The height of the screen, of course,
can be derived from the length of the array and the width. Implement a function
drawHorizontalLine(byte[] screen, int width, int x1, int x2, int y) which draws a horizontal
line from (x1, y) to (x2, y).

*/

#include <iostream>
#include <bitset>

using namespace std;

class Solution
{
public:
    void drawHorizontalLine(char* screen, int width, int x1, int x2, int y)
    {
        int start_offset = x1 % 8;
        int start_byte = x1 / 8;
        if (start_offset) start_byte++;

        int end_offset = x2 % 8;
        int end_byte = x2 / 8;
        if (end_offset != 7) end_byte--; // not a whole byte

        // set bytes
        for (int i = start_byte; i <= end_byte; i++) {
            screen[y * width / 8 + i] = 0xff;
        }

        int start_mask = (0xff >> start_offset);
        int end_mask = (0xff << (8 - end_offset - 1));
        //int end_mask = ~(0xff >> (end_offset + 1));

        if ((x1 / 8) == (x2 / 8)) { // same byte
            int mask = start_mask & end_mask;
            screen[y * (width / 8) + x1 / 8] |= mask;
        } else {
            if (start_offset) {
                screen[y * (width / 8) + start_byte - 1] |= start_mask;
            }

            if (end_offset != 7) {
                screen[y * (width / 8) + end_byte + 1] |= end_mask;
            }
        }
    }
};

void dumpScreen(char *screen, int len, int width)
{
    for (int i = 0; i < len; i++) {
        if (i && i % (width / 8 ) == 0) cout  << endl;
        cout << bitset<8>(screen[i]).to_string() << ' ';
    }
    cout << endl;
}

int main(int argc, const char* argv[])
{

    const int len = 32; // screen total size
    char screen[len]; // screen array
    Solution sol;

    int x1 = 3, x2 = 15, y = 2;
    int width = 32; // 4 bytes

    memset(screen, 0, len);
    sol.drawHorizontalLine(screen, width, x1, x2, y);
    dumpScreen(screen, len, width);

    return 0;
}
