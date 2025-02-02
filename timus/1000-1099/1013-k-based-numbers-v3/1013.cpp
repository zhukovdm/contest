/**
 * https://acm.timus.ru/problem.aspx?space=1&num=1013
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

using ull = unsigned long long;
using matrix = std::array<std::array<__uint128_t, 2>, 2>;

auto mat_exp(matrix &l, matrix &r, __uint128_t mod) -> matrix
{
    matrix result;

    result[0][0] = (((l[0][0] * r[0][0]) % mod) + ((l[0][1] * r[1][0]) % mod)) % mod;
    result[0][1] = (((l[0][0] * r[0][1]) % mod) + ((l[0][1] * r[1][1]) % mod)) % mod;
    result[1][0] = (((l[1][0] * r[0][0]) % mod) + ((l[1][1] * r[1][0]) % mod)) % mod;
    result[1][1] = (((l[1][0] * r[0][1]) % mod) + ((l[1][1] * r[1][1]) % mod)) % mod;

    return result;
}

auto bin_exp(matrix &m, ull n, __uint128_t mod) -> matrix
{
    auto r = m;

    while (n) {
        if (n & 1) {
            r = mat_exp(r, m, mod);
        }
        m = mat_exp(m, m, mod);
        n >>= 1;
    }

    return r;
}

auto main(int, char **) -> int
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ull n, k, m;
    std::cin >> n >> k >> m;

    matrix matrix = {{{0, 1}, {(__uint128_t)(k - 1), (__uint128_t)(k - 1)}}};
    std::cout << (ull)(bin_exp(matrix, n, m)[0][1]) << std::endl;

    return 0;
}
