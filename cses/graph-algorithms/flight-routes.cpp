/**
 * https://cses.fi/problemset/task/1196
 *
 * The problem requires to find k disjoint shortest paths. Find the k shortest
 * paths for each vector.
 *
 * The approach from this solution keeps reopening edges no matter if vertex
 * is in the min heap or not. A better approach would be to create a custom
 * heap with decrease operation directly on vertices added to the heap.
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

auto solve() -> void
{
    ll n, m, k, a, b, c;
    cin >> n >> m >> k;

    vector<vector<pair<ll, ll>>> edges(n);

    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        edges[--a].push_back({--b, c});
    }

    vector<ll> dists[n];

    auto cmp = [](const pair<ll, ll> &l, const pair<ll, ll> &r) { return l.first > r.first; };

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, decltype(cmp)> q(cmp);
    q.push({0, 0});

    while (!q.empty()) {
        auto x = q.top();
        q.pop();
        auto [total_dist, fr] = x;

        if ((ll)dists[fr].size() >= k) { // !
            continue;
        }
        dists[fr].push_back(total_dist);
        for (auto [to, dist] : edges[fr]) {
            q.push({total_dist + dist, to});
        }
    }

    for (int i = 0; i < (int)dists[n - 1].size(); ++i) {
        cout << dists[n - 1][i] << " \n"[i == k - 1];
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
