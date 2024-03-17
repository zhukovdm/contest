/**
 * https://cses.fi/problemset/task/1667
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

    int n, m, a, b, fst, lst;
    cin >> n >> m;

    fst = 0;
    lst = n - 1;

    vector<vector<int>> edges(n, vector<int>());
    vector<int> preds(n, -1);
    vector<int> dists(n, numeric_limits<int>::max());
    dists[0] = 0;

    for (int i = 1; i <= m; ++i) {
        cin >> a >> b;
        --a;
        --b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    queue<int> queue;
    queue.push(fst);

    while (!queue.empty()) {
        auto &&fr = queue.front();

        for (auto &&to : edges[fr]) {

            /**
             * Here, the right condition is to check whether has been visited
             * against the distance. Predecessors do not work (we cannot write
             * preds[to] == -1, because it would overwrite the source vertex).
             */
            if (dists[to] == numeric_limits<int>::max()) {
                preds[to] = fr;
                dists[to] = dists[fr] + 1;
                queue.push(to);
            }
            if (to == lst) { // early termination
                break;
            }
        }
        queue.pop();
    }

    if (preds[lst] == -1) {
        cout << "IMPOSSIBLE\n";
    }
    else {
        vector<int> res(1, lst);
        while (preds[res.back()] != -1) {
            res.push_back(preds[res.back()]);
        };
        reverse(res.begin(), res.end());

        std::cout << (int)res.size() << '\n';
        for (int i = 0; i < (int)res.size(); ++i) {
            std::cout << res[i] + 1 << " \n"[i == (int)res.size() - 1];
        }
    }
    return 0;
}
