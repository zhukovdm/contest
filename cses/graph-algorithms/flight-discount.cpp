/**
 * https://cses.fi/problemset/task/1195
 *
 * Find a path and an edge on the path that if halved, we get the shortest
 * path across all possible paths.
 *
 * Run Dijkstra on G and G^T to find out the distances from 1 to all and from
 * N to all. Then, for each edge (u ~> v), find the shortest distance as:
 *
 *              min(dist[u] + dist[v] + weight[u][v] / 2).
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
using xx = tuple<int, ll, bool>;

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

constexpr ll INF = (ll)1e18;

struct item {
    ll fr, dist;
};

auto dijkstra(vector<vector<pair<ll, ll>>> &edges, ll v) -> vector<ll>
{
    ll n = (int)edges.size();

    vector<ll> dists(n, INF);
    dists[v] = 0;

    auto cmp = [](item &l, item &r) { return l.dist > r.dist; };

    priority_queue<item, vector<item>, decltype(cmp)> q(cmp);
    q.push({v, 0});

    while (!q.empty()) {
        auto item = q.top();
        q.pop();
        if (dists[item.fr] != item.dist) {
            continue;
        }
        for (auto [to, dist] : edges[item.fr]) {
            if (dists[to] > dists[item.fr] + dist) {
                dists[to] = dists[item.fr] + dist;
                q.push({to, dists[to]});
            }
        }
    }

    return dists;
}

auto solve() -> void
{
    ll n, m, a, b, c;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> dir_edges(n), rev_edges(n);

    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        --a;
        --b;
        dir_edges[a].push_back({b, c});
        rev_edges[b].push_back({a, c});
    }

    auto source_dists = dijkstra(dir_edges, 0 - 0);
    auto target_dists = dijkstra(rev_edges, n - 1);

    ll result = INF;

    for (int fr = 0; fr < n; ++fr) {
        for (auto [to, dist] : dir_edges[fr]) {
            result = min(result, source_dists[fr] + dist / 2 + target_dists[to]);
        }
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
