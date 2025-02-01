/**
 * https://acm.timus.ru/problem.aspx?space=1&num=1000
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

auto main(int, char **) -> int
{
    using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    scanf("%d%d", &a, &b);

    printf("%d\n", a + b);

    return 0;
}
