/**
 * https://acm.timus.ru/problem.aspx?space=1&num=1009
 */

#include <algorithm>
#include <bit>
#include <cassert>
#include <chrono>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <functional>
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

#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif

/**
 * No memoization whatsoever.
 */

auto func(int n, int k, bool was_zero) -> long long
{
    long long res = 0;

    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return was_zero ? k - 1 : k;
    }

    if (!was_zero) {
        res += func(n - 1, k, true);
    }
    res += (k - 1) * func(n - 1, k, false);

    return res;
}

auto main(int, char **) -> int
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::cout << func(n, k, true) << '\n';

    return 0;
}
