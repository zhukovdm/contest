/**
 * https://cses.fi/problemset/task/1676
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

class dsu {
private:
    std::vector<int> comps_;

public:
    dsu(int size) : comps_(size, -1)
    {
    }
    auto find(int v) -> int
    {
        return comps_[v] < 0 ? v : (comps_[v] = find(comps_[v]));
    }
    auto size(int v) -> int
    {
        return -comps_[find(v)];
    }
    auto are_same(int u, int v) -> bool
    {
        return find(u) == find(v);
    }
    auto unite(int u, int v) -> bool
    {
        u = find(u);
        v = find(v);
        if (u == v) {
            return false;
        }
        if (comps_[u] > comps_[v]) {
            std::swap(u, v);
        }
        comps_[u] += comps_[v];
        comps_[v] = u;
        return true;
    }
};

auto main(int, char **) -> int
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, a, b;
    cin >> n >> m;
    int max_size = 1, comp_cnt = n;
    dsu s(n);

    for (int i = 1; i <= m; ++i) {
        cin >> a >> b;
        --a;
        --b;
        bool change = s.unite(a, b);
        cout << (change ? --comp_cnt : comp_cnt) << ' ' << (max_size = max(max_size, s.size(a))) << '\n';
    }
    return 0;
}
