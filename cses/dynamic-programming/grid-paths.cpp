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

auto solve() -> void
{
    int n;
    char c;

    cin >> n;
    vector<ll> paths_old(n, 0);
    paths_old[0] = 1;

    for (int i = 0; i < n; ++i) {
        vector<ll> paths_new(n, 0);
        for (int j = 0; j < n; ++j) {
            cin >> skipws >> c;
            if (c == '.') {
                paths_new[j] = (paths_old[j] + ((j > 0) ? paths_new[j - 1] : 0)) % MOD;
            }
            // else { /* do nothing */ }
        }
        paths_old = move(paths_new);
    }

    cout << paths_old[n - 1] << '\n';
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
