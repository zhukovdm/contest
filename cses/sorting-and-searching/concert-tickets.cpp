/**
 * https://cses.fi/problemset/task/1091
 *
 * 9 3 9 6 6 8 6 2 6 3 ~>
 * 9 5 4 6 3 9 3 3 5 2
 *
 * (9,2) (8,1) (6,4) (3,2) (2,1)
 *
 * 9 ~> 9      (9,1) (8,1) (6,4) (3,2) (2,1)
 * 5 ~> 3      (9,1) (8,1) (6,4) (3,1) (2,1)
 * 4 ~> 3      (9,1) (8,1) (6,4) (3,0) (2,1)
 * 6 ~> 6
 * 3 ~> 2
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

constexpr char EOL = '\n';

auto main(int argc, char **argv) -> int
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m;

    std::cin >> n >> m;

    std::vector<int> t;
    std::map<int, int, std::greater<int>> h;

    while (n--) {
        int hi;
        std::cin >> hi;
        auto it = h.insert({hi, 1});
        if (!it.second) {
            ++it.first->second;
        }
    }

    while (m--) {
        int ti;
        std::cin >> ti;
        t.emplace_back(ti);
    }

    for (auto &&customer : t) {
        auto b = h.lower_bound(customer);
        auto ans = (b == h.end()) ? -1 : b->first;
        std::cout << ans << EOL;

        if (b != h.end() && b->second == 1) {
            h.erase(b->first);
        }
        --b->second;
    }

    return 0;
}
