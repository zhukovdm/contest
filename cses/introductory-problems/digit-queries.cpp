/**
 * https://cses.fi/problemset/task/2431
 */

#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

using ll = long long;
using ull = unsigned long long;

constexpr char ZERO = '0';

auto solve(ull k) -> int
{
    ull number = 0;
    ull digits = 0;

    ull idx = 1;
    ull fact = 9;

    for (;;) {

        ull new_number = number + fact; // possibly 10, 100, 1000, ...
        ull new_digits = digits + idx * fact;

        ++idx;
        fact *= 10;

        if (new_digits > k) {
            --idx;
            break;
        }

        number = new_number;
        digits = new_digits;
    }

    auto offset = (k - digits + idx - 1) / idx; // ceiling!
    auto rem = (k - digits == 0) ? 0 : (k - digits - 1) % idx;

    return to_string(number + offset)[rem] - ZERO;
}

auto main(int, char **) -> int
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ull q, k;

    cin >> q;

    while (q--) {
        cin >> k;
        cout << solve(k) << '\n';
    }

    return 0;
}
