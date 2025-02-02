/**
 * https://acm.timus.ru/problem.aspx?space=1&num=1051
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

using namespace std;

using ll = long long;

#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif

/**
 * To rule out rectangles with a (mod 3) side, observe that stones can be
 * embedded into a grid, where each stone has a coordinate (x, y). Calculate
 * (x % 3 + y % 3) % 3 and observe, that the initial parity of all knots is
 * the same and remains the same after jumps (invariant). To with only one
 * stone we need to get a configuration with 1 0 0, and this is not possible!
 *
 * There is another case when... (finish proof!)
 *
 * - https://prase.cz/kalva/imo/isoln/isoln933.html
 */

auto main(int, char **) -> int
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;

    if (m == 1 || n == 1) {
        cout << ((max(m, n) + 1) / 2) << '\n';
    }
    else {
        cout << ((m % 3 == 0 || n % 3 == 0) ? 2 : 1) << '\n';
    }

    return 0;
}
