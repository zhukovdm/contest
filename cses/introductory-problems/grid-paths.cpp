#include <iostream>
#include <map>
#include <set>
#include <vector>

using ll = long long;
using ul = unsigned long;
using ull = unsigned long long;

constexpr char END_OF_LINE = '\n';

constexpr int S = 7;

constexpr char Q = '?';
constexpr char L = 'L';
constexpr char R = 'R';
constexpr char U = 'U';
constexpr char D = 'D';

int cnt = 0;
std::string path;
int board[S + 2][S + 2] = {};

int r_dir[] = {0, 0, 1, -1};
int c_dir[] = {1, -1, 0, 0};

auto solve(int row, int col, int steps_done) -> int
{
    if (row == S && col == 1) {
        return static_cast<std::size_t>(steps_done) >= path.size() ? 1 : 0;
    }
    if (board[row][col - 1] && board[row][col + 1] && !board[row - 1][col] && !board[row + 1][col]) {
        return 0;
    }
    if (board[row - 1][col] && board[row + 1][col] && !board[row][col - 1] && !board[row][col + 1]) {
        return 0;
    }

    int cnt = 0;

    if (path[steps_done] == Q) {

        for (int i = 0; i < 4; ++i) {
            int r = row + r_dir[i];
            int c = col + c_dir[i];

            auto &ceil = board[r][c];

            if (!ceil) {
                ceil = 1;
                cnt += solve(r, c, steps_done + 1);
                ceil = 0;
            }
        }
    }

    else {

        if (path[steps_done] == L) {
            --col;
        }
        if (path[steps_done] == R) {
            ++col;
        }
        if (path[steps_done] == U) {
            --row;
        }
        if (path[steps_done] == D) {
            ++row;
        }

        auto &ceil = board[row][col];

        if (!ceil) {
            ceil = 1;
            cnt += solve(row, col, steps_done + 1);
            ceil = 0;
        }
    }

    return cnt;
}

auto main(int, char **) -> int
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> path;

    for (int i = 0; i <= S + 1; ++i) {
        board[0][i] = 1;
        board[S + 1][i] = 1;
        board[i][0] = 1;
        board[i][S + 1] = 1;
    }

    board[1][1] = 1; // busy tile!
    std::cout << solve(1, 1, 0) << END_OF_LINE;

    return 0;
}
