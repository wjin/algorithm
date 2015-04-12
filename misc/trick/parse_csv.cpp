#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// get item starting with quote and return next position
int GetItemQuote(const string &line, string &item, int idx)
{
    int pos = idx;
    int len = line.size();

    for (; pos < len; pos++) {
        // item end
        if (pos == len - 1 || (line[pos] == '"' && line[pos + 1] == ',')) {
            pos++;
            break;
        }

        // special case for consecutive two quotes
        if (line[pos] == '"' && line[pos + 1] == '"') {
            pos++;
        }

        item += line[pos];
    }

    return pos;
}

// get item without quote and return next position
int GetItemNoQuote(const string &line, string &item, int idx)
{
    int pos = idx;
    int len = line.size();

    for (; pos < len; pos++) {
        if (line[pos] == ',') break;
        item += line[pos];
    }

    return pos;
}

// parse line
void ParseLine(vector<string> &result, const string &line)
{
    int len = line.size();
    if (len == 0) return;

    int idx = 0, pos = 0;

    do {
        string item;
        if (idx < len && line[idx] == '"') { // item starts with quote
            ++idx; // skip "
            pos = GetItemQuote(line, item, idx);
        } else { // no quote
            pos = GetItemNoQuote(line, item, idx);
        }

        result.push_back(item);
        idx = pos + 1; // skip delimiter ,

    } while (pos < len);
}

// parse csv
bool ParseCSV(vector<vector<string>> &result, const string &csv)
{
    auto beg = csv.begin();
    while (beg < csv.end()) {
        auto delim = find(beg, csv.end(), '\r'); // split csv
        string line = string(beg, delim);

        result.push_back(vector<string>());
        ParseLine(result.back(), line);

        // check item count
        if (result.back().size() != result[0].size()) {
            result.clear();
            return false;
        }

        beg = delim + 2; // skip \r and \n
    }

    return true;
}

void DumpVec(const vector<vector<string>> &vec)
{
    for (auto &row : vec) {
        for (auto col : row) {
            cout << col << " | ";
        }
        cout << endl << endl;
    }
}

int main(int argc, char *argv[])
{
    vector<string> csvSample = {
        // valid cases
        "x,x",
        "x,x\r\ny,y",
        "x,x\r\ny,y\r\n",

        "x,x\r\ny,y\r\nz,\"z\"\r\n",
        "x,x\r\ny,y\r\nz,\"z,\"\r\n",
        "x,x\r\ny,y\r\nz,\"z\n\"\r\n",
        "x,x\r\ny,y\r\nz,\"z\"\"\r\n",
        "x,x\r\ny,y\r\nz,\"z\"\"\"\r\n",

        "\"x,a\nb\"\"c\nd\",y,\"z\nb\"\"c\nd\"\r\n\"x,a\nb\"\"c\nd\",y,\"z\nb\"\"c\nd\"\r\n\"x,a\nb\"\"c\nd\",y,\"z\nb\"\"c\nd\"\r\n",

        // invalid cases
        "x,x\r\ny,y,y",
        "x,x\r\ny,y,y\r\n",
    };

    vector<vector<string>> ret;
    for (auto csv : csvSample) {
        if (ParseCSV(ret, csv)) {
            DumpVec(ret);
        } else {
            cout << "Invalid" << endl;
        }

        cout << "========" << endl;
        ret.clear();
    }

    return 0;
}
