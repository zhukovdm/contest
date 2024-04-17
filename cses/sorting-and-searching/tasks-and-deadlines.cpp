/**
 * https://cses.fi/problemset/task/1630/
 *
 * See https://www.geeksforgeeks.org/cses-solutions-tasks-and-deadlines/ for a proof.
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

struct task {
    int duration;
    int deadline;
};

auto solve() -> void
{
    int n, a, d;
    cin >> n;

    vector<task> tasks;

    for (int i = 0; i < n; ++i) {
        cin >> a >> d;
        tasks.push_back({a, d});
    }

    auto cmp = [](const task &l, const task &r) { return l.duration < r.duration; };
    sort(tasks.begin(), tasks.end(), cmp);

    ll result = 0, cur_time = 0;

    for (auto &&task : tasks) {
        cur_time += task.duration;
        result += task.deadline - cur_time;
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
