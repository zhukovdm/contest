/**
 * https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/
 *
 * Explain!
 */

#include <iostream>
#include <vector>

using namespace std;

constexpr int DIM = 30;
constexpr int NIL = -1;
const vector<pair<int, int>> offsets = {{0, +1}, {+1, 0}, {0, -1}, {-1, 0}};

class Solution {
public:
    bool exist = false;
    int ROWS, COLS, timer = 0, comp_cnt = 0, vert_cnt = 0;
    vector<vector<int>> grid, tins, lows;

    Solution() : tins(DIM, vector<int>(DIM, 0)), lows(DIM, vector<int>(DIM, 0))
    {
    }

    bool within_bounds(int coord, int max_coord)
    {
        return coord >= 0 && coord < max_coord;
    }

    void is_articulation(int row_curr, int col_curr, bool root)
    {
        ++vert_cnt;
        tins[row_curr][col_curr] = lows[row_curr][col_curr] = ++timer;
        int child_cnt = 0;
        for (auto &&[row_off, col_off] : offsets) {
            auto row_next = row_curr + row_off;
            auto col_next = col_curr + col_off;
            if (within_bounds(row_next, ROWS) && within_bounds(col_next, COLS)) {
                // tree edge
                if (grid[row_next][col_next] != 0 && tins[row_next][col_next] == 0) {
                    is_articulation(row_next, col_next, false);
                    if (lows[row_next][col_next] >= tins[row_curr][col_curr] && !root) {
                        exist = true;
                    }
                    lows[row_curr][col_curr] = min(lows[row_curr][col_curr], lows[row_next][col_next]);
                    ++child_cnt;
                }
                // back edge
                else if (grid[row_next][col_next] != 0) {
                    lows[row_curr][col_curr] = min(lows[row_curr][col_curr], tins[row_next][col_next]);
                }
            }
        }
        if (root && child_cnt > 1) { // root!
            exist = true;
        }
    }

    int minDays(vector<vector<int>> &grid)
    {
        this->grid = move(grid);
        ROWS = static_cast<int>(this->grid.size());
        COLS = static_cast<int>(this->grid[0].size());
        for (int row = 0; row < ROWS; ++row) {
            for (int col = 0; col < COLS; ++col) {
                if (this->grid[row][col] == 1 && tins[row][col] == 0) {
                    ++comp_cnt;
                    is_articulation(row, col, true); // new root
                }
            }
        }
        if (vert_cnt == 1) {
            return 1;
        }
        if (comp_cnt != 1) {
            return 0;
        }
        return exist ? 1 : 2;
    }
};

int main(int argc, char **argv)
{

    // vector<vector<int>> grid{
    //     {1, 1},
    // };

    vector<vector<int>> grid{
        {1, 1, 0, 1, 1},
        {1, 1, 1, 1, 1},
        {1, 1, 0, 1, 1},
        {1, 1, 0, 1, 1},
    };

    // vector<vector<int>> grid{
    //     {1, 0, 1},
    //     {1, 1, 1},
    //     {1, 0, 1},
    // };

    Solution s;
    cout << s.minDays(grid) << endl;

    return 0;
}
