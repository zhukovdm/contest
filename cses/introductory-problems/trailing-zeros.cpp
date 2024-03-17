/**
 * https://cses.fi/problemset/task/1618
 */

#include <iostream>

#define ll long long
#define ull unsigned long long

auto main(int, char **) -> int
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ull n;
    std::cin >> n;

    ull result = 0, d = 5;

    while (d <= n) {
        result += n / d;
        d *= 5;
    }

    std::cout << result << '\n';

    return 0;
}

/*

How many 5 divisors are contained in the multiplication?

1 = 1
2 = 2
...
5 = 5
...
10 = 2 * 5
...
15 = 3 * 5
...
25 = 5 * 5

  count numbers divisible by 5
+ count numbers divisible by 5 * 5
+ count numbers divisible by 5 * 5 * 5

Therefore, we increase result by (n / 5^k) for all k, for which (5^k < n).

*/
