/**
 * https://cses.fi/problemset/task/1629
 */

#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using ld = long double;
using ui = unsigned int;
using ul = unsigned long;
using ull = unsigned long long;

using vi = std::vector<int>;
using pii = std::pair<int, int>;

constexpr int MAX = (int)1e9;
constexpr int MOD = MAX + 7;
constexpr char EOL = '\n';

auto main(int argc, char **argv) -> int
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::vector<pii> times;
    int n, a, b;

    std::cin >> n;
    while (n--) {
        std::cin >> a >> b;
        times.emplace_back(a, b);
    }

    std::sort(times.begin(), times.end(), [](const pii &p1, const pii &p2) { return p1.second < p2.second; });

    int ans = 0, nxt = 0;

    for (auto &&t : times) {
        if (t.first >= nxt) {
            ++ans;
            nxt = t.second;
        }
    }

    std::cout << ans << EOL;

    return 0;
}
