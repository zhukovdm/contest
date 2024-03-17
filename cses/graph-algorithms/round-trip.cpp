/**
 * https://cses.fi/problemset/task/1669
 *
 * The graph need not be connected + undirected graph might have
 * only dfs tree and back edges (no forward, no cross). Thus, we
 * need to detect a back edge that points to a vertex other than
 * its parent. Once such a vertex detected.
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

constexpr int N = (int)1e5 + 1;

bool found = false;
int n, m, a, b, t, cycle_fst = -1, cycle_lst = -1;
vector<int> edges[N], parents(N, -1), visited(N, false);

auto dfs(int fr) -> void
{
    visited[fr] = true;
    for (auto &&to : edges[fr]) {
        if (!found) {
            if (!visited[to]) {
                parents[to] = fr;
                dfs(to);
            }
            else if (parents[fr] != to) {
                found = true;
                cycle_fst = to;
                cycle_lst = fr;
            }
        }
    }
}

auto main(int, char **) -> int
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i) {
        if (!found && !visited[i]) {
            dfs(i);
        }
    }
    if (!found) {
        cout << "IMPOSSIBLE" << '\n';
    }
    else {
        vector<int> result;
        result.push_back(cycle_fst);
        result.push_back(cycle_lst);
        do {
            cycle_lst = parents[cycle_lst];
            result.push_back(cycle_lst);
        } while (cycle_lst != cycle_fst);
        reverse(result.begin(), result.end());
        cout << result.size() << '\n';
        for (auto &&vertex : result) {
            cout << vertex << ' ';
        }
    }
    return 0;
}
