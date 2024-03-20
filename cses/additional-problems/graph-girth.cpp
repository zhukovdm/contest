/**
 * https://cses.fi/problemset/task/1707
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

constexpr int INF = numeric_limits<int>::max();

auto bfs(vector<vector<int>> &edges, int n, int v) -> int
{
    int girth = INF;
    vector<int> dist(n, INF), parent(n, -1);
    vector<bool> visited(n, false);

    dist[v] = 0;
    visited[v] = true;

    queue<int> q;
    q.push(v);

    while (!q.empty()) {
        int fr = q.front();
        q.pop();
        for (auto to : edges[fr]) {
            if (!visited[to]) {
                visited[to] = true;
                dist[to] = dist[fr] + 1;
                parent[to] = fr;
                q.push(to);
            }
            else if (to != parent[fr]) { // cycle
                girth = min(girth, dist[fr] + dist[to] + 1);
            }
        }
    }

    return girth;
}

auto solve() -> void
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> edges(n);

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    int girth = INF;

    for (int i = 0; i < n; ++i) {
        girth = min(girth, bfs(edges, n, i));
    }

    cout << (girth < INF ? girth : -1) << endl;
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
