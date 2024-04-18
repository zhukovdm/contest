/**
 * https://cses.fi/problemset/task/1631/
 *
 * The idea is to sort the input, let Kotivalo perform the heaviest task and
 * give Justiina start from the lightest task. By the time Kotivalo finishes his
 * task, he can certainly take the lightest task. Better described at [1].
 *
 * [1] https://www.geeksforgeeks.org/cses-solutions-reading-books/
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

auto solve() -> void
{
    ll n, t, kotivalo, justiina, result;
    cin >> n;

    vector<ll> times;

    for (int i = 0; i < n; ++i) {
        cin >> t;
        times.push_back(t);
    }
    sort(times.begin(), times.end());

    kotivalo = justiina = 0;

    for (int i = 0; i < n - 1; ++i) {
        justiina += times[i];
    }
    kotivalo = times[n - 1];

    result = (kotivalo >= justiina) ? (kotivalo * 2) : (justiina + kotivalo);
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
