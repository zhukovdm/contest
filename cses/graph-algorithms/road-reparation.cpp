/**
 * https://cses.fi/problemset/task/1675/
 *
 * Find a minimum spanning tree using Kruskal's algorithm.
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

class dsu {
private:
    std::vector<int> comps_;

public:
    dsu(int size) : comps_(size, -1)
    {
    }

    auto find(int v) -> int
    {
        return comps_[v] < 0 ? v : (comps_[v] = find(comps_[v]));
    }

    auto size(int v) -> int
    {
        return -comps_[find(v)];
    }

    auto are_same(int u, int v) -> bool
    {
        return find(u) == find(v);
    }

    auto unite(int u, int v) -> bool
    {
        u = find(u);
        v = find(v);
        if (u == v) {
            return false;
        }
        if (comps_[u] > comps_[v]) {
            std::swap(u, v);
        }
        comps_[u] += comps_[v];
        comps_[v] = u;
        return true;
    }
};

struct edge {
    int fr, to;
    ll dist;
};

auto solve() -> void
{
    int n, m, a, b;
    ll c, result = 0;
    cin >> n >> m;

    vector<edge> edges;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b >> c;
        edges.push_back({--a, --b, c});
    }

    auto cmp = [](edge &l, edge &r) { return l.dist < r.dist; };
    sort(edges.begin(), edges.end(), cmp);

    dsu d(n);

    for (auto [fr, to, cost] : edges) {
        if (!d.are_same(fr, to)) {
            result += cost;
            d.unite(fr, to);
        }
    }
    cout << (d.size(0) == n ? to_string(result) : "IMPOSSIBLE") << '\n';
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
