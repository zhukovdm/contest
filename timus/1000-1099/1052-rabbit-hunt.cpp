/**
 * https://acm.timus.ru/problem.aspx?space=1&num=1052
 */

#include <algorithm>
#include <bit>
#include <cassert>
#include <chrono>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;

#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif

auto main(int, char **) -> int
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<pair<int, int>> points;
    int n, x, y;

    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        points.push_back({x, y});
    }

    /**
     * The main idea is to avoid finding slope as a ratio, instead use
     * the product.
     */

    int max_cnt = 0;

    for (int i = 0; i < ssize(points) - 2; ++i) {
        for (int j = i + 1; j < ssize(points) - 1; ++j) {
            auto [xi, yi] = points[i];
            auto [xj, yj] = points[j];
            int cnt = 0;
            for (int k = j + 1; k < ssize(points); ++k) {
                auto [xk, yk] = points[k];
                cnt += ((yi - yj) * (xi - xk) == (yi - yk) * (xi - xj)) ? 1 : 0;
            }
            max_cnt = max(cnt, max_cnt);
        }
    }
    cout << max_cnt + 2 << '\n';

    return 0;
}
