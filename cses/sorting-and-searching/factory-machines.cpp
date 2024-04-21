/**
 * https://cses.fi/problemset/task/1620
 *
 * The idea is to load each machine all the time to use maximum capacity.
 * The worst case scenario if we have only one machine with k_{1} = 10^9
 * and a total of 10^9 products. The time necessary for any configuration
 * to complete a given amount of products cannot exceed 10^18. We look for
 * the minimum time in the interval [1, ..., 10^18], such that the amount
 * of produced products equals exactly the given amount.
 *
 * The binary search is rather tricky, because given large enough K, it can
 * overflow. Thus, we have to break summation early.
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
    ll n, t, result = 0;
    cin >> n >> t;

    vector<ll> times(n);

    for (int i = 0; i < n; ++i) {
        cin >> times[i];
    }

    ll MAX = (ll)1e18;
    ll l = 1, r = MAX;

    while (l <= r) {
        ll m = (l + r) / 2; // round down!
        ll p = 0;
        for (int i = 0; i < n; ++i) {
            p += m / times[i];

            // 10^18 is very close to the (long long) limit!
            if (p >= MAX) {
                break;
            }
        }
        if (p < t) {
            l = m + 1;
        }
        else {
            result = m;
            r = m - 1;
        }
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
