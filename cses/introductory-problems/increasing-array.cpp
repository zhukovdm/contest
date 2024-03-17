/**
 * https://cses.fi/problemset/task/1094
 */

#include <algorithm>
#include <iostream>

#define ull unsigned long long

using namespace std;

ull n, sum = 0, temp, last;

auto main(int, char **) -> int
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> last;

    while (n-- > 1) {
        cin >> temp;
        if (temp < last) {
            sum += last - temp;
        }
        last = max(temp, last);
    }

    cout << sum << '\n';

    return 0;
}
