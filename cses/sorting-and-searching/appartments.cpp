/**
 * https://cses.fi/problemset/task/1084
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using ll = long long;
using ul = unsigned long;
using ull = unsigned long long;

auto main(int argc, char **argv) -> int
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> a, b;

    while (n--) {
        int ai;
        std::cin >> ai;
        a.push_back(ai);
    }

    while (m--) {
        int bi;
        std::cin >> bi;
        b.push_back(bi);
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    ul cnt = 0, j = 0;

    for (ul i = 0; i < a.size(); ++i) {

        while (j < b.size() && b[j] < a[i] - k) {
            ++j;
        }
        if (j >= b.size()) {
            break;
        }
        if (a[i] - k <= b[j] && b[j] <= a[i] + k) {
            ++cnt;
            ++j;
        }
    }

    std::cout << cnt << '\n';

    return 0;
}
