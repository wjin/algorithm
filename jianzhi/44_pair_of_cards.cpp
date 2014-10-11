#include <iostream>
#include <vector>

using namespace std;

struct Card {
    enum Type { HEART, SPADE, DIAMOND, CLUB, MAX };
    static const int MAXVAL = 14;

    Type type;
    int val;

    Card(Type t = HEART, int v = 0) : type(t), val(v) {}

    vector<Card> genCard(int n)
    {
        srand(time(nullptr));
        vector<Card> ret;
        if (n <= 0) return ret;

        vector<vector<bool>> used(MAX, vector<bool>(MAXVAL, false));

        int king = 0;
        while (n) {
            Type t = static_cast<Type>(random() % MAX);
            int val = random() % MAXVAL;

            if (val == 0 && king > 2) {
                continue;
            } else {
                king++;
            }

            if (used[t][val]) continue;

            used[t][val] = true;
            ret.push_back(Card(t, val));
            n--;
        }

        return ret;
    }
};

class Solution
{
private:
    void dump(vector<Card> &v)
    {
        for (auto e : v) {
            cout << e.type << ' ' << e.val;
            cout << endl;
        }
    }

    static bool cmp(const Card &lhs, const Card &rhs)
    {
        return lhs.val < rhs.val;
    }

public:
    bool isStraight(vector<Card> &v)
    {
        sort(v.begin(), v.end(), cmp);

        int zeroCnt = 0, gap = 0;
        int idx = 0;

        // count number of king
        while (v[idx].val == 0) {
            idx++;
            zeroCnt++;
        }

        // count gaps
        idx++;
        while (idx < v.size()) {
            if (v[idx].val == v[idx - 1].val) return false; // pair
            gap += v[idx].val - v[idx - 1].val;

            idx++;
        }

        return gap <= zeroCnt;
    }

    void test()
    {
        Card obj;
        int numOfCard = 5;

        for (int idx = 0; idx < 10; idx++) {
            vector<Card> cards = obj.genCard(numOfCard);
            dump(cards);
            cout << isStraight(cards) << endl;
        }
    }
};

int main(int argc, char *argv[])
{
    Solution sol;

    sol.test();

    return 0;
}
