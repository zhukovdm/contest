/**
 * https://cses.fi/problemset/task/1757
 *
 * The first idea is to make a lexicographic topological sorting with priority
 * queue. But it won't work in the example below. Lex is 3 ~> 2 ~> 4 ~> 1 ~> 5.
 *
 * 3
 *  \|
 *   2
 *    \|
 *     5
 *    /|
 *   1
 *  /|
 * 4
 *
 * But the right answer to the problem is 4 ~> 1 ~> 3 ~> 2 ~> 5, because we
 * can finish 1 before 2. Thus, we should first find out the smallest vertex
 * that follows.
 *
 * We might use a priority queue with pairs of (smallest_successor, vertex).
 * The previous approach does not work on the following graph. The right answer
 * is 5 7 2 4 3 6 1, but the algorithm returns 4 3 5 6 7 2 1.
 *
    7
    6
    2 1
    7 2
    5 7
    6 1
    3 6
    4 3
 *
 * I have not managed to find working DFS-first interpretation. We loose too
 * much information about common successors and how far they are in the chain.
 *
 * Another approach is not entirely obvious and emerges from looking at G^T.
 * How we would actually treat the graph given above? We must process 1 at the
 * end and there is no other options. Then, we add 6, because we can perform 2
 * later (to ensure the condition from the problem statement).
 *
 * _ _ _ _ _ _ 1
 * _ _ _ _ _ 6 1
 * _ _ _ _ 3 6 1
 * _ _ _ 4 3 6 1
 * _ _ 2 4 3 6 1
 * _ 7 2 4 3 6 1
 * 5 7 2 4 3 6 1
 *
 * The algorithm is finite and at each step we preserve the condition. Thus, we
 * have proved the correctness.
 *
 * When reading edges, we should reverse them. Then, we should make Kahn's algo-
 * rithm with *MAX* priority queue, because we want vertices with higher labels
 * as close to the end as possible.
 */

#include <algorithm>
#include <bit>
#include <cassert>
#include <chrono>
#include <cmath>
// #include <ext/pb_ds/assoc_container.hpp>
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
// #include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

auto start_time = chrono::high_resolution_clock::now();
auto elapsed_time() -> double
{
    using namespace chrono;
    return static_cast<double>(duration_cast<microseconds>(high_resolution_clock::now() - start_time).count()) / 1e6;
}

#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif

struct vertex {
    int cnt;
    vector<int> out;

    vertex() : cnt(0)
    {
    }
};

auto solve() -> void
{
    int n, m, a, b;
    cin >> n >> m;

    vector<vertex> courses(n + 1);

    for (int i = 1; i <= m; ++i) {
        cin >> a >> b;
        courses[b].out.push_back(a);
        ++courses[a].cnt;
    }

    priority_queue<int, vector<int>, less<int> /* ! */> q;

    for (int i = 1; i <= n; ++i) {
        if (courses[i].cnt == 0) {
            q.push(i);
        }
    }

    vector<int> result;

    while (!q.empty()) {
        auto fr = q.top();
        q.pop();
        result.push_back(fr);

        for (auto &&to : courses[fr].out) {
            --courses[to].cnt;
            if (courses[to].cnt == 0) {
                q.push(to);
            }
        }
    }
    reverse(result.begin(), result.end());

    for (int i = 0; i < n; ++i) {
        cout << result[i] << ' ';
    }
    cout << '\n';
}

auto main(int, char **) -> int
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt = 1;
    // cin >> tt;
    for (int t = 1; t <= tt; ++t) {
#ifdef LOCAL
        cerr << "+++ CASE: #" << t << " START\n";
#endif
        solve();
#ifdef LOCAL
        cerr << "+++ CASE: #" << t << " END\n";
        cerr << "+++ Time: " << setprecision(6) << elapsed_time() << " s\n";
        cerr << "@@@@@@@@@@@@@@@@@@@@\n";
#endif
    }

    return 0;
}
