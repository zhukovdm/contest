/**
 * https://cses.fi/problemset/task/1680
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

constexpr int INF = static_cast<int>(1e9);

struct vertex {
    int cnt, len, pred;
    vector<int> out;

    vertex() : cnt(0), len(0), pred(-1)
    {
    }
};

auto solve() -> void
{
    int n, m, a, b;
    cin >> n >> m;

    vector<vertex> cities(n + 1);

    for (int i = 1; i <= m; ++i) {
        cin >> a >> b;
        cities[a].out.push_back(b);
        ++cities[b].cnt;
    }

    queue<int> q;

    for (int i = 2; i <= n; ++i) {
        if (cities[i].cnt == 0) {
            q.push(i);
        }
    }

    // remove vertices we should not start from

    while (!q.empty()) {
        auto fr = q.front();
        q.pop();
        for (auto &&to : cities[fr].out) {
            if (--cities[to].cnt == 0 && to != 1) {
                q.push(to);
            }
        }
    }

    // try to travel 1 ~> N

    q.push(1);

    while (!q.empty()) {
        auto fr = q.front();
        q.pop();
        for (auto &&to : cities[fr].out) {
            if (cities[to].len < cities[fr].len + 1) {
                cities[to].len = cities[fr].len + 1;
                cities[to].pred = fr;
            }
            if (--cities[to].cnt == 0) {
                q.push(to);
            }
        }
    }

    if (cities[n].pred == -1) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        auto cur = n;
        vector<int> result;
        while (cur > 0) {
            result.push_back(cur);
            cur = cities[cur].pred;
        }
        reverse(result.begin(), result.end());
        cout << result.size() << '\n';
        for (int i = 0; i < (int)result.size(); ++i) {
            cout << result[i] << " \n"[i == (int)result.size() - 1];
        }
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
