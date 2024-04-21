/**
 * https://cses.fi/problemset/task/1158
 *
 * Classic knapsack problem solved dynamically. The idea is to add books one
 * by one and keep the maximum amount of pages achievable for a price from the
 * interval [0, ..., x]. It is not required to have the entire table in memory,
 * and counts from the previous step are enough to get the next state.
 */

#include <algorithm>
#include <bit>
#include <cassert>
#include <chrono>
#include <cmath>
// #include <ext/pb_ds/assoc_container.hpp>
#include <functional>
#include <iomanip>
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
// #include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

auto start_time = chrono::high_resolution_clock::now();
auto elapsed_time() -> double
{
    using namespace chrono;
    return static_cast<double>(duration_cast<microseconds>(high_resolution_clock::now() - start_time).count()) / 1e6;
}

#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif

auto solve() -> void
{
    int n, x, count, result = 0;
    cin >> n >> x;

    vector<int> prices(n); // weights

    vector<int> counts_old(x + 1, -1);
    counts_old[0] = 0;

    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> count; // profit
        vector<int> counts_new = counts_old;

        for (int j = 0; j < (int)counts_old.size() - prices[i]; ++j) {
            auto next_price = prices[i] + j;
            counts_new[next_price] = max(counts_new[next_price], counts_old[j] + count);
        }
        counts_old = move(counts_new);
    }

    for (auto it = counts_old.begin(); it != counts_old.end(); ++it) {
        result = max(result, *it);
    }

    cout << result << '\n';
}

auto main(int, char **) -> int
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; ++t) {
#ifdef LOCAL
        cerr << "+++ CASE: #" << t << " START\n";
#endif
        solve();
#ifdef LOCAL
        cerr << "+++ CASE: #" << t << " END\n";
        cerr << "+++ Time: " << setprecision(6) << elapsed_time() << " s\n";
        cerr << "@@@@@@@@@@@@@@@@@@@@\n";
#endif
    }

    return 0;
}
