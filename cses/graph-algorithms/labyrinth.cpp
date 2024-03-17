/**
 * https://cses.fi/problemset/task/1193
 */

#include <algorithm>
#include <bit>
#include <cassert>
#include <chrono>
#include <cmath>
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
#include <tuple>
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

array<tuple<int, int, char>, 4> moves = {{
    {-1, +0, 'U'},
    {+0, +1, 'R'},
    {+1, +0, 'D'},
    {+0, -1, 'L'},
}};

auto main(int, char **) -> int
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, row_end = -1, col_end = -1;
    cin >> n >> m;

    char c;
    vector<vector<char>> labyrinth(n + 2, vector<char>(m + 2, '#'));
    vector<vector<pair<int, int>>> preds(n + 2, vector<pair<int, int>>(m + 2, {-1, -1}));

    queue<pair<int, int>> queue;

    for (int row = 1; row <= n; row++) {
        for (int col = 1; col <= m; col++) {
            cin >> skipws >> c; // getting rid of WHITE chars!
            switch (c) {
            case 'A':
                // remains '#'
                queue.push({row, col});
                break;
            case 'B':
                row_end = row;
                col_end = col;
                labyrinth[row][col] = '.';
                break;
            default:
                labyrinth[row][col] = c;
            }
        }
    }

    while (!queue.empty()) {
        auto [row_cur, col_cur] = queue.front();
        for (int i = 0; i < 4; i++) {
            auto [row_dif, col_dif, dir] = moves[i];
            int row_new = row_cur + row_dif;
            int col_new = col_cur + col_dif;

            if (labyrinth[row_new][col_new] == '.') {
                labyrinth[row_new][col_new] = dir;
                preds[row_new][col_new] = {row_cur, col_cur};
                queue.push({row_new, col_new});
            }
            if (row_new == row_end && col_new == col_end) {
                break;
            }
        }
        queue.pop();
    }

    if (preds[row_end][col_end].first == -1 /*&& preds[row_end][col_end].second == -1*/) {
        cout << "NO\n";
    }
    else {
        vector<pair<int, int>> path(1, {row_end, col_end});
        while (labyrinth[path.back().first][path.back().second] != '#') {
            path.push_back(preds[path.back().first][path.back().second]);
        }
        path.pop_back();
        reverse(path.begin(), path.end());

        cout << "YES\n";
        cout << path.size() << '\n';
        for (auto &&dir : path) {
            cout << labyrinth[dir.first][dir.second];
        }
        cout << '\n';
    }
    return 0;
}
