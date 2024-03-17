/**
 * https://cses.fi/problemset/task/1197
 *
 * Theorem.
 *
 * Adding super-vertex with distances to all edges 0 does not introduce new
 * negative cycles or disrupt old ones. In other words, (...) is a negative
 * cycle in G if and only if (...) is a negative cycle in G'.
 *
 * Proof.
 *
 * => Look at the same cycle in G', edges of G remained. Thus, the same cycle
 * still exists.
 *
 * <= No cycle can go through the super-vertex. We can leave this vertex but
 * we cannot come back. Thus, adding new super-vertex does not introduce new
 * cycles.
 *
 * The proof of why the algorithm finds a negative cycle is placed in the
 * solutions to CLRS exercises.
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

constexpr ll INF = static_cast<ll>(1e9) * 2501;

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
    ll n, m;
    cin >> n >> m;

    vector<vector<pair<int, ll>>> edges(n + 1);
    for (int i = 1; i <= n; ++i) {
        edges[0].push_back({i, 0});
    }

    vector<int> preds(n + 1, -1);
    vector<ll> dists(n + 1, INF);
    dists[0] = 0;

    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        edges[a].push_back({b, c});
    }

    for (int ph = 0; ph < n /* (n + 1) - 1 */; ++ph) {
        for (int fr = 1; fr <= n; ++fr) {
            for (auto [to, cost] : edges[fr]) {
                if (dists[fr] + cost < dists[to]) {
                    preds[to] = fr;
                    dists[to] = dists[fr] + cost;
                }
            }
        }
    }

    int bad = -1;

    for (int fr = 1; fr <= n; ++fr) {
        for (auto [to, cost] : edges[fr]) {
            if (dists[fr] + cost < dists[to]) {
                bad = fr;
            }
        }
    }

    if (bad == -1) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        vector<bool> visited(n + 1, false);
        auto cur = bad;
        while (!visited[cur]) {
            visited[cur] = true;
            cur = preds[cur];
        }
        auto rep = cur;
        vector<int> cycle;

        do {
            cycle.push_back(cur);
            cur = preds[cur];
        } while (cur != rep);

        cycle.push_back(rep);
        reverse(cycle.begin(), cycle.end());

        for (auto &&v : cycle) {
            cout << v << ' ';
        }
        cout << '\n';
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
        cerr << "+++ CASE: #" << t << " +++\n";
#endif
        solve();
#ifdef LOCAL
        cerr << "+++ CASE: #" << t << " +++\n";
        cerr << "+++ Time: " << setprecision(6) << elapsed_time() << " s\n";
        cerr << "@@@@@@@@@@@@@@@@@@@@\n";
#endif
    }

    return 0;
}
