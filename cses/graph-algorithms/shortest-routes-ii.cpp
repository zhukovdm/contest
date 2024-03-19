/**
 * https://cses.fi/problemset/task/1672
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

constexpr ll INF = 1000 * static_cast<ll>(1e9);

auto solve() -> void
{
    int n, m, q;
    cin >> n >> m >> q;

    // initialization

    vector<vector<ll>> dists(n + 1, vector<ll>(n + 1, -1));
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            dists[i][j] = (i == j) ? 0 : INF;
        }
    }

    for (int i = 0; i < m; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        dists[a][b] = dists[b][a] = min(dists[a][b], c);
    }

    // floyd-warshall

    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dists[i][j] = min(dists[i][j], dists[i][k] + dists[k][j]);
            }
        }
    }

    // queries

    for (int i = 0; i < q; ++i) {
        int fr, to;
        cin >> fr >> to;
        cout << ((dists[fr][to] == INF) ? -1 : dists[fr][to]) << '\n';
    }
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
