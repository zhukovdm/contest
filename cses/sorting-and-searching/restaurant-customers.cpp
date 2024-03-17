/**
 * https://cses.fi/problemset/task/1619
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using ld = long double;
using ui = unsigned int;
using ul = unsigned long;
using ull = unsigned long long;

constexpr char EOL = '\n';

auto main(int argc, char **argv) -> int
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::map<int, int> m;
    int n, a, b;

    std::cin >> n;

    while (n--) {
        std::cin >> a >> b;
        m[a] = +1;
        m[b] = -1;
    }

    int ans = 0, cur = 0;

    for (const auto &elem : m) {
        cur += elem.second;
        ans = (cur > ans) ? cur : ans;
    }

    std::cout << ans << EOL;

    return 0;
}
