/**
 * https://cses.fi/problemset/task/1668
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

    const string NEGATIVE("IMPOSSIBLE\n");

    int n, m, a, b;
    cin >> n >> m;

    vector<vector<int>> edges(n, vector<int>());
    vector<int> colors(n, -1);

    // initialization

    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        --a;
        --b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    for (int i = 0; i < n; ++i) {
        if (colors[i] == -1) {
            colors[i] = 0;

            // stack-based dfs

            stack<pair<int, int>> stack;
            stack.push({i, 0});

            while (!stack.empty()) {
                auto p = stack.top();
                stack.pop();
                auto [fr, color] = p;

                int new_color = (color + 1) % 2;

                for (auto &&to : edges[fr]) {
                    if (colors[to] == -1) {
                        colors[to] = new_color;
                        stack.push({to, new_color});
                    }
                }
            }
        }
    }

    // unreachable components

    if (any_of(colors.begin(), colors.end(), [](const int &color) { return color == -1; })) {
        cout << NEGATIVE;
        return 0;
    }

    // bad edge

    for (int fr = 0; fr < n; ++fr) {
        for (auto &&to : edges[fr]) {
            if (colors[fr] == colors[to]) {
                cout << NEGATIVE;
                return 0;
            }
        }
    }

    // proper bipartite graph

    for (auto &&color : colors) {
        cout << color + 1 << ' ';
    }
    cout << '\n';

    return 0;
}
