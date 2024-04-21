/**
 * https://acm.timus.ru/problem.aspx?space=1&num=1083
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

std::array<int, 4> dx = {1, 0, -1, 0};
std::array<int, 4> dy = {0, 1, 0, -1};

auto main(int, char **) -> int
{
    using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k, r = 1;
    string s;

    cin >> n >> s;
    k = ssize(s);

    while (n > 0) {
        r *= n;
        n -= k;
    }

    cout << r << '\n';

    return 0;
}
