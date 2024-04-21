/**
 * https://acm.timus.ru/problem.aspx?space=1&num=2034
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

/**
 * The idea is to identify vertices that lie on all shortest paths, and then
 * find the one closest to the location of robers.
 *
 * We perform two from given `source` and `target`. In each, we count how many
 * shortest paths lead to the destination and destination holds the desired sum.
 * Critical vertices are the ones, which count up to number of shortest paths
 * between s ~> t or opposite.
 *
 *   2   6
 *  / \ / \
 * 1-3-5   8
 *  \ / \ /
 *   4   7
 *
 * The 1st BFS would return [1, 1, 1, 1, 3, 3, 3, 6]
 * The 2nd BFS would return [6, 2, 2, 2, 2, 1, 1, 1]
 *
 * 1, 5, and 8 are critical vertices.
 *
 * However, this condition does not guarantee that a vertex lies on a path,
 * We have to additionally verify that the distance from the `source` to a
 * critical vector and then to the `target` is equal to the distance of a
 * shortest path.
 *
 * The approach described above is problematic, because the number of shortest
 * paths in a graph may grow exponentially! Consider layered graph with edges
 * between all nodes in the adjacent layers. Each layer triples number of paths.
 *
 *   o-o- ... -o
 *  / \         \
 * s-o-o- ... -o-t
 *  \ /         /
 *   o-o- ... -o
 */

/**
 * Another approact is based on the same idea, that we need to detect the dis-
 * tance from `r` to any vertex. `s` and `f` are among critical vertices. The
 * main idea is that all queued vertices pass through a critical vertex all at
 * once. From the algorithm, a bad number might be propagated from a non-cri-
 * tical vertex. In fact, this value might end up set on a vertex. But a right
 * value will be set thanks to max (this will reset bad propagations), and min
 * (this will set good value out of two criticals).
 */

constexpr int INF = static_cast<int>(1e9);

class ugraph {
public:
    const int order_;
    std::vector<std::vector<int>> edges_;

    ugraph(int n) : order_(n), edges_(std::vector<std::vector<int>>(n))
    {
    }

    auto add(int fr, int to) -> void
    {
        edges_[fr].push_back(to);
        edges_[to].push_back(fr);
    }
};

auto bfs1(ugraph &g, int source) -> std::vector<int>
{
    std::vector<int> dist(g.order_, INF);
    dist[source] = 0;

    std::queue<int> q;
    q.push(source);

    while (!q.empty()) {
        auto fr = q.front();

        for (auto &&to : g.edges_[fr]) {
            if (dist[to] == INF) {
                dist[to] = dist[fr] + 1;
                q.push(to);
            }
        }
        q.pop();
    }
    return dist;
}

auto bfs2(ugraph &g, const std::vector<int> &r_dist, int s, int f) -> std::vector<int>
{
    std::vector<int> s_dist(g.order_, INF);
    s_dist[s] = 0;

    std::vector<int> result(g.order_, -1);
    result[s] = r_dist[s];

    std::queue<int> q;
    q.push(s);

    while (!q.empty()) {
        auto fr = q.front();
        auto cand_dist = s_dist[fr] + 1;

        for (auto &&to : g.edges_[fr]) {
            if (cand_dist <= s_dist[to]) {
                if (result[to] == -1) {
                    result[to] = std::min(result[fr], r_dist[to]);
                    s_dist[to] = cand_dist;
                    q.push(to);
                }
                else {
                    result[to] = std::max(result[fr], result[to]);
                    result[to] = std::min(result[to], r_dist[to]);
                }
            }
        }
        q.pop();
    }
    return result;
}

auto main(int, char **) -> int
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m, fr, to, s, f, r;
    std::cin >> n >> m;

    ugraph g(n);

    while (m--) {
        std::cin >> fr >> to;
        g.add(--fr, --to);
    }

    std::cin >> s >> f >> r;
    --s;
    --f;
    --r;

    auto result = bfs2(g, bfs1(g, r), s, f);
    std::cout << result[f] << '\n';

    return 0;
}
