/**
 * https://cses.fi/problemset/task/1617
 */

#include <algorithm>
#include <iostream>

using namespace std;

using ull = unsigned long long;

int n;
ull r = 1;
ull m = static_cast<ull>(1e9) + 7;

auto main(int, char **) -> int
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    while (n--) {
        r = (r * 2) % m;
    }

    cout << r << '\n';

    return 0;
}
