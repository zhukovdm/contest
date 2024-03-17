/**
 * https://cses.fi/problemset/task/1071
 */

#include <iostream>

auto main(int, char **) -> int
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    unsigned long t;
    std::cin >> t;

    while (t--) {

        long long r, c;
        long long m, ma, mi;
        long long n, d;

        long long result;

        std::cin >> r >> c;

        m = std::max(r, c);
        ma = m * m;
        mi = (m - 1) * (m - 1) + 1;

        if (r > c) {
            n = (m % 2 == 0) ? ma : mi;
            d = (m % 2 == 0) ? -1 : +1;
        }

        else {
            n = (m % 2 == 0) ? mi : ma;
            d = (m % 2 == 0) ? +1 : -1;
        }

        result = n + d * std::min(r, c) - d * 1;

        std::cout << result << '\n';
    }

    return 0;
}
