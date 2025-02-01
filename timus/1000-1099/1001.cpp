/**
 * https://acm.timus.ru/problem.aspx?space=1&num=1001
 */

#include <algorithm>
#include <bit>
#include <cassert>
#include <chrono>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
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

    double number;
    vector<double> result;

    while (cin >> number) {
        result.push_back(number);
    }

    for (auto it = result.rbegin(); it != result.rend(); ++it) {
        printf("%.4f\n", sqrt(*it));
    }

    return 0;
}
