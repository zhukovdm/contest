/**
 * https://cses.fi/problemset/task/1072
 *
 * Count how to place 2x knights on NxN board, this is n * (n - 1) / 2.
 * Subtract number of ways two knight could attack each other. Count how
 * many ways exist to place the following rectangles on the board?
 *
 * x . | . x | x . . | . . x
 * . . | . . | . . x | x . .
 * . x | x . |       |
 *
 * That is (n-1)(n-2).
 */

#include <iostream>

using namespace std;

#define ll long long
#define ull unsigned long long

int main(int argc, char **argv)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll b, r;

    cin >> b;

    for (ll i = 1; i <= b; ++i) {
        r = i * i * (i * i - 1) / 2;
        if (i > 2) {
            r -= 4 * (i - 1) * (i - 2);
        }
        cout << r << '\n';
    }

    return 0;
}
