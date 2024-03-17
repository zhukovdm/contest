/**
 * https://cses.fi/problemset/task/1681
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

constexpr ll MOD = static_cast<ll>(1e9) + 7;

struct vertex {
    ll deg, cnt;
    vector<int> out;

    vertex() : deg(0), cnt(0)
    {
    }
};

auto solve() -> void
{
    int n, m, a, b;
    cin >> n >> m;

    vector<vertex> levels(n + 1);
    levels[1].deg = 1; // !

    for (int i = 1; i <= m; ++i) {
        cin >> a >> b;
        levels[a].out.push_back(b);
        ++levels[b].cnt;
    }

    queue<int> q;

    // remove bad vertices

    for (int fr = 2; fr <= n; ++fr) {
        if (levels[fr].cnt == 0) {
            q.push(fr);
        }
    }

    while (!q.empty()) {
        auto fr = q.front();
        q.pop();

        for (auto &&to : levels[fr].out) {
            if (--levels[to].cnt == 0 && to != 1 /* ! */) {
                q.push(to);
            }
        }
    }

    // find counts

    q.push(1);

    while (!q.empty()) {
        auto fr = q.front();
        q.pop();

        for (auto &&to : levels[fr].out) {
            levels[to].deg = (levels[to].deg + levels[fr].deg) % MOD;
            if (--levels[to].cnt == 0) {
                q.push(to);
            }
        }
    }

    cout << levels[n].deg << '\n';
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
