/**
 * https://acm.timus.ru/problem.aspx?space=1&num=1014
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
    int n;
    vector<int> counts(10, 0), divisors{2, 3, 5, 7};

    cin >> n;

    if (n == 0) {
        cout << 10 << '\n';
        return;
    }
    if (n == 1) {
        cout << n << '\n';
        return;
    }
    for (int i = 9; i > 1; --i) {
        while (n % i == 0) {
            ++counts[i];
            n /= i;
        }
    }
    if (n > 1) {
        cout << -1;
    }
    else {
        for (int i = 2; i < 10; ++i) {
            while (counts[i]--) {
                cout << i;
            }
        }
    }
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
        cerr << "@ Case: #" << t << '\n';
#endif
        solve();
#ifdef LOCAL
        cerr << "@ Case: #" << t << '\n';
        cerr << "@ Time: " << setprecision(6) << elapsed_time() << " s" << '\n';
        cerr << "@@@@@@@@@@@@@@@@@@@@" << '\n';
#endif
    }

    return 0;
}
