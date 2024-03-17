/**
 * https://cses.fi/problemset/task/1678
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

enum class status { unseen, opened, closed };

struct vertex {
    status stt;
    vector<int> out;

    vertex() : stt(status::unseen)
    {
    }
};

vector<int> cycle;
vector<vertex> cities;

auto dfs(int fr) -> bool
{
    cities[fr].stt = status::opened;
    cycle.push_back(fr);

    for (auto &&to : cities[fr].out) {
        if (cities[to].stt == status::opened) {
            cycle.push_back(to);
            return true;
        }
        else if (cities[to].stt == status::unseen) {
            auto is_cycle = dfs(to);
            if (is_cycle) {
                return true;
            }
        }
    }
    cycle.pop_back();
    cities[fr].stt = status::closed;
    return false;
}

auto solve() -> void
{
    int n, m, a, b;
    cin >> n >> m;

    cities.resize(n + 1);

    for (int i = 1; i <= m; ++i) {
        cin >> a >> b;
        cities[a].out.push_back(b);
    }

    auto is_cycle = false;

    for (int fr = 1; !is_cycle && fr <= n; ++fr) {
        if (cities[fr].stt == status::unseen) {
            is_cycle = dfs(fr);
        }
    }

    if (is_cycle) {
        auto it = find(cycle.begin(), cycle.end(), cycle[(int)cycle.size() - 1]);
        cout << cycle.end() - it << '\n';
        for (; it != cycle.end(); ++it) {
            cout << *it << ' ';
        }
        cout << '\n';
    }
    else {
        cout << "IMPOSSIBLE\n";
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
