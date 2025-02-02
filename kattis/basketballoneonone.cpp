/**
 * https://open.kattis.com/problems/basketballoneonone
 */

#include <algorithm>
#include <bit>
#include <cassert>
#include <chrono>
#include <cmath>
// #include <ext/pb_ds/assoc_container.hpp>
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

auto main(int, char **) -> int
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    cout << s[s.size() - 2] << '\n';
    return 0;
}
