/**
 * https://cses.fi/problemset/task/1624
 */

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

using ll = long long;
using ull = unsigned long long;

constexpr int SIZE = 8;
constexpr char EMPTY = '.';

int result = 0;
vector<string> board;

bool cl[SIZE], ld[2 * SIZE], rd[2 * SIZE];

auto set_piece(int row, int col, bool value) -> void
{
    cl[col] = value;
    ld[row + col] = value;
    rd[row - col + SIZE - 1] = value;
}

auto solve(int row) -> void
{
    if (row >= SIZE) {
        ++result;
    }

    else {
        for (int col = 0; col < SIZE; ++col) {
            if (board[row][col] == EMPTY && !cl[col] && !ld[row + col] && !rd[row - col + SIZE - 1]) {
                set_piece(row, col, true);
                solve(row + 1);
                set_piece(row, col, false);
            }
        }
    }
}

auto main(int argc, char **argv) -> int
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    {
        std::string line;
        for (int i = 0; i < 8; ++i) {
            std::cin >> line;
            board.push_back(line);
        }
    }

    solve(0);
    std::cout << result << '\n';

    return 0;
}
