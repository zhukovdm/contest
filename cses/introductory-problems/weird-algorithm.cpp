/**
 * https://cses.fi/problemset/task/1068
 */

#include <iostream>

using namespace std;

int main()
{
    long long int i;
    cin >> i;

    cout << i << ' ';
    while (i != 1) {
        if ((i & 1) == 0) {
            i /= 2;
        }
        else {
            i = 3 * i + 1;
        }
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}
