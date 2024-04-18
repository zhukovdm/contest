/**
 * https://cses.fi/problemset/task/1202/
 *
 * Idea is to use Dijkstra and propagate necessary changes through the graph.
 * Shorter path reset values, paths of the same length update values.
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

constexpr ll INF = (ll)(1e18);
constexpr ll MOD = (ll)(1e9) + 7;

auto solve() -> void
{
    ll n, m, a, b, c;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> edges(n);

    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        edges[--a].push_back({--b, c});
    }

    vector<ll> dists(n, INF), paths(n, 0), min_counts(n, INF), max_counts(n, 0);

    dists[0] = min_counts[0] = max_counts[0] = 0;
    paths[0] = 1;

    auto cmp = [](pair<ll, ll> &l, pair<ll, ll> &r) { return l.first > r.first; };

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, decltype(cmp)> q(cmp);
    q.push({0, 0});

    while (!q.empty()) {
        auto [dist_fr, fr] = q.top();
        q.pop();
        if (dist_fr != dists[fr]) {
            continue; // skip not minimum possible
        }
        for (auto [to, dist] : edges[fr]) {
            // better path ~> reset
            if (dists[to] > dist_fr + dist) {
                dists[to] = dist_fr + dist;
                paths[to] = paths[fr];
                min_counts[to] = min_counts[fr] + 1;
                max_counts[to] = max_counts[fr] + 1;
                q.push({dists[to], to});
            }
            // path of the known length ~> upd. counters
            else if (dists[to] == dist_fr + dist) {
                paths[to] = (paths[fr] + paths[to]) % MOD;
                min_counts[to] = min(min_counts[to], min_counts[fr] + 1);
                max_counts[to] = max(max_counts[to], max_counts[fr] + 1);
            }
        }
    }

    cout << dists[n - 1] << ' ' << paths[n - 1] << ' ' << min_counts[n - 1] << ' ' << max_counts[n - 1] << '\n';
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
