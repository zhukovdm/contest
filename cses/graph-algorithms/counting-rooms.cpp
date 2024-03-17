/**
 * https://cses.fi/problemset/task/1192
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

array<pair<int, int>, 4> moves = {{
    {-1, +0}, // U
    {+0, +1}, // R
    {+1, +0}, // D
    {+0, -1}, // L
}};

auto dfs(vector<vector<char>> &field, int row_ini, int col_ini) -> void
{
    stack<pair<int, int>> stack;

    field[row_ini][col_ini] = '#';
    stack.push({row_ini, col_ini});

    while (!stack.empty()) {
        auto pos_cur = stack.top();
        stack.pop();

        auto [row_cur, col_cur] = pos_cur;
        for (int i = 0; i < 4; ++i) {
            auto [row_dif, col_dif] = moves[i];
            int row_new = row_cur + row_dif;
            int col_new = col_cur + col_dif;

            if (field[row_new][col_new] == '.') {
                field[row_new][col_new] = '#';
                stack.push({row_new, col_new});
            }
        }
    }
}

auto main(int, char **) -> int
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, room_cnt = 0;

    cin >> n >> m;
    vector<vector<char>> field(n + 2, vector<char>(m + 2, '#'));

    for (int row = 1; row <= n; ++row) {
        for (int col = 1; col <= m; ++col) {
            char c;
            cin >> skipws >> c;
            field[row][col] = c;
        }
    }

    for (int row = 1; row <= n; ++row) {
        for (int col = 1; col <= m; ++col) {
            if (field[row][col] == '.') {
                ++room_cnt;
                dfs(field, row, col);
            }
        }
    }

    cout << room_cnt << '\n';

    return 0;
}
