/**
 * https://cses.fi/problemset/task/1755
 */

#include <algorithm>
#include <iostream>

#define ull unsigned long long

using namespace std;

constexpr int DIM = 26; // ['A', ..., 'Z']

bool check_cnts(const int (&arr)[DIM], int &index)
{
    int odds = 0;
    for (int i = 0; i < DIM; i++) {
        if ((arr[i] & 0x1) != 0) {
            ++odds;
            index = i;
        }
    }
    return odds == 0 || odds == 1;
}

int main(int argc, char **argv)
{
    ios::sync_with_stdio(false);

    int cnts[DIM] = {0};
    char temp;
    int index = -1;
    bool correct;

    while (temp = getchar(), temp >= 'A' && temp <= 'Z') {
        cnts[temp - 'A'] += 1;
    }

    correct = check_cnts(cnts, index);
    if (!correct) {
        cout << "NO SOLUTION" << '\n';
    }

    else {
        for (int i = 0; i < DIM; i++) {
            for (int j = 0; j < cnts[i] >> 1; j++) {
                cout << (char)(i + 'A');
            }
        }
        if (index >= 0) {
            cout << (char)(index + 'A');
        }
        for (int i = DIM - 1; i >= 0; i--) {
            for (int j = 0; j < cnts[i] >> 1; j++) {
                cout << (char)(i + 'A');
            }
        }
        cout << '\n';
    }

    return 0;
}
