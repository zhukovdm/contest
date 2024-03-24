/**
 * https://cses.fi/problemset/task/1673
 *
 * The problem is about finding a positive cycle. Positive cycle always have
 * an edge (u ~> v) that increases the distance on the v-vertex.
 *
 * We need to consider only vertices reachable from 1 and N. Thus, use DFS
 * on G and G^T.
 *
 * Run Bellman-Ford on the graph to find distances. After N - 1 phases, the
 * algorithm should converge. Look for an edge that could increase distance
 * on any vertex reachable from 1 and N.
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

auto dfs(vector<vector<pair<ll, ll>>> &edges, vector<bool> &visited, ll fr) -> void
{
    visited[fr] = true;
    for (auto [to, _] : edges[fr]) {
        if (!visited[to]) {
            dfs(edges, visited, to);
        }
    }
}

auto solve() -> void
{
    ll n, m, a, b, c;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> edges(n), rev_edges(n);

    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        --a;
        --b;
        edges[a].push_back({b, c});
        rev_edges[b].push_back({a, c});
    }

    // calculate reachability

    vector<bool> reach(n, false);
    dfs(edges, reach, 0);

    vector<bool> rev_reach(n, false);
    dfs(rev_edges, rev_reach, n - 1);

    for (int v = 0; v < n; ++v) {
        reach[v] = reach[v] & rev_reach[v];
    }

    // bellman ford

    vector<ll> dists(n, -INF);
    dists[0] = 0;

    for (int phase = 0; phase < n - 1; ++phase) {
        for (int fr = 0; fr < n; ++fr) {
            for (auto [to, dist] : edges[fr]) {
                if (reach[fr] && reach[to]) {
                    dists[to] = max(dists[to], dists[fr] + dist);
                }
            }
        }
    }

    // check edges

    auto result = dists[n - 1];

    for (int fr = 0; fr < n; ++fr) {
        for (auto [to, dist] : edges[fr]) {
            if (reach[fr] && reach[to] && dists[to] < dists[fr] + dist) {
                result = -1;
            }
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
