/**
 * https://cses.fi/problemset/task/1090
 *
 * Input is tricky, we cannot proceed greedily.
 *
 * 10 15
 * 9 8 8 9 10 8 5 8 7 10
 *
 * 5 8 | 7 8 | 8 | 8 | 8 | 9 | 9 | 10 | 10
 *
 * Do a map with number of occurrences. Try to pair right with left, move pointers.
 *
 * (5, 1) (7, 1) (8, 4) (9, 2) (10, 2)
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using ll = long long;
using ul = unsigned long;
using ull = unsigned long long;

constexpr char EOL = '\n';

auto main(int argc, char **argv) -> int
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, x;
    std::cin >> n >> x;

    std::vector<int> children;

    while (n--) {
        int pi;
        std::cin >> pi;
        children.push_back(pi);
    }

    std::sort(children.begin(), children.end()); // ! not in O(n)

    int l = 0;
    int r = children.size() - 1;

    int cnt = 0;

    while (l <= r) {
        int s = children[l] + children[r];
        if (s <= x && l < r) {
            ++cnt;
            ++l;
        }
        else if (children[r] <= x) {
            ++cnt;
        }
        --r;
    }

    std::cout << cnt << EOL;

    return 0;
}
