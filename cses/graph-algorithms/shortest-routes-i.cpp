/**
 * https://cses.fi/problemset/task/1671
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

using namespace std;

using ll = long long;
using pl = pair<ll, ll>;

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
    int n, m, a, b, c;
    cin >> n >> m;

    vector<vector<pair<ll, ll>>> edges(n + 1);
    vector<ll> preds(n + 1, -1);
    vector<ll> dists(n + 1, numeric_limits<ll>::max());
    vector<bool> visited(n + 1, false);

    for (int t = 1; t <= m; t++) {
        cin >> a >> b >> c;
        edges[a].push_back({c, b});
    }

    priority_queue<pl, vector<pl>, std::greater<pl>> q;
    q.push({0, 1});
    dists[1] = 0;

    while (!q.empty()) {
        auto p = q.top();
        q.pop();
        auto [dist_fr_new, fr] = p;
        if (!visited[fr]) { // !
            visited[fr] = true;
            for (auto [dist_fr_to, to] : edges[fr]) {
                auto dist_to_new = dists[fr] + dist_fr_to;
                if (dists[to] > dist_to_new) {
                    dists[to] = dist_to_new;
                    q.push({dist_to_new, to});
                }
            }
        }
    }
    for_each(/*skip 0th*/ ++dists.begin(), dists.end(), [](ll &dist) { cout << dist << ' '; });
    cout << '\n';
}

auto main(int, char **) -> int
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; ++t) {
#ifdef LOCAL
        cerr << "+++ Case: #" << t << '\n';
#endif
        solve();
#ifdef LOCAL
        cerr << "+++ Case: #" << t << '\n';
        cerr << "+++ Time: " << setprecision(6) << elapsed_time() << " s" << '\n';
        cerr << "++++++++++++++++++++" << '\n';
#endif
    }

    return 0;
}
