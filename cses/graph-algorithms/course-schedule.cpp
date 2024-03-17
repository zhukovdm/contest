/**
 * https://cses.fi/problemset/task/1679
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

struct vertex {
    int before_cnt;
    vector<int> after;

    vertex() : before_cnt(0)
    {
    }
};

auto solve() -> void
{
    int n, m, a, b;
    cin >> n >> m;

    vector<vertex> courses(n + 1);

    for (int i = 1; i <= m; ++i) {
        cin >> a >> b;
        courses[a].after.push_back(b);
        ++courses[b].before_cnt;
    }

    queue<int> q;

    for (int i = 1; i <= n; ++i) {
        if (courses[i].before_cnt == 0) {
            q.push(i);
        }
    }

    vector<int> result;

    while (!q.empty()) {
        auto fr = q.front();
        q.pop();
        result.push_back(fr);

        for (auto &&to : courses[fr].after) {
            --courses[to].before_cnt;
            if (courses[to].before_cnt == 0) {
                q.push(to);
            }
        }
    }

    bool bad = false;

    for (int i = 1; i <= n; ++i) {
        if (courses[i].before_cnt > 0) {
            bad = true;
        }
    }

    if (bad) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        for (auto &&v : result) {
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
