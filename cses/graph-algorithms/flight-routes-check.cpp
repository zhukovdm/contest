/**
 * https://cses.fi/problemset/task/1682
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
 * We want to detect a pair of vertices u, v such that there is NO directed
 * path from u to v.
 *
 * Lemma. In a directed graph G, for any pair u, v in V there is a directed
 * path u ~> ... ~> v if and only if BFS/DFS performed from any w in V finds
 * all vertices in both G and G^T.
 *
 * => BFS/DFS started from any vertex will find all vertices and this is
 * directly implied by the existence of a path between a pair of vertices.
 * Why will it find in G^T? For a fixed pair u, v, there is a path P1 btwn
 * u ~> ... ~> v. There is also a path P2 btwn v ~> ... ~> u. It means u is
 * reachable from v in G^T via transposed P1, and v is reachable from u via
 * transposed P2.
 *
 * <= By contradiction. Suppose there is a pair u, v in V, between which no
 * directed path in G. Start BFS/DFS from u. The search finds u, but since no
 * path, it will not find v. Thus, condradicting assumption that the search
 * would discover all vertices.
 */

auto dfs(vector<bool> &visited, vector<vector<int>> &neighbors, int u) -> void
{
    visited[u] = true;
    for (auto &&v : neighbors[u]) {
        if (!visited[v]) {
            dfs(visited, neighbors, v);
        }
    }
}

auto main(int, char **) -> int
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, a, b;
    cin >> n >> m;

    vector<bool> visited;

    vector<vector<int>> neighborsN(n, vector<int>());
    vector<vector<int>> neighborsT(n, vector<int>());

    for (int i = 1; i <= m; ++i) {
        cin >> a >> b;
        --a;
        --b;
        neighborsN[a].push_back(b);
        neighborsT[b].push_back(a);
    }

    visited.assign(n, false);
    dfs(visited, neighborsN, 0);

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            cout << "NO" << '\n' << 0 + 1 << ' ' << i + 1 << '\n';
            return 0;
        }
    }

    visited.assign(n, false);
    dfs(visited, neighborsT, 0);

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            cout << "NO" << '\n' << i + 1 << ' ' << 0 + 1 << '\n';
            return 0;
        }
    }

    cout << "YES" << '\n';
    return 0;
}
