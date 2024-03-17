/**
 * https://cses.fi/problemset/task/1666
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

/**
 * Find components and connect them by base vertices.
 */

auto dfs(const vector<vector<int>> &edges, vector<int> &visited, int bs)
{
    visited[bs] = bs;

    stack<int> stack;
    stack.push(bs);

    while (!stack.empty()) {
        auto fr = stack.top();
        stack.pop();

        for (auto &&to : edges[fr]) {
            if (visited[to] < 0) {
                visited[to] = bs;
                stack.push(to);
            }
        }
    }
}

auto main(int, char **) -> int
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n, vector<int>());

    for (int i = 0; i < m; i++) {
        int fr, to;
        cin >> fr >> to;
        fr--;
        to--;
        edges[fr].push_back(to);
        edges[to].push_back(fr);
    }

    vector<int> comps;
    vector<int> visited(n, -1);

    for (int fr = 0; fr < n; fr++) {
        if (visited[fr] == -1) {
            comps.push_back(fr);
            dfs(edges, visited, fr);
        }
    }

    cout << (int)comps.size() - 1 << '\n';
    for (int i = 1; i < (int)comps.size(); i++) {
        cout << comps[i - 1] + 1 << ' ' << comps[i] + 1 << '\n';
    }

    return 0;
}
