#include <stack>
#include <vector>

using namespace std;

int INF = (int)1e9 + 1;
int ROWS, COLS;

vector<int> r_dif{0, 0, 1, -1};
vector<int> c_dif{1, -1, 0, 0};

void dfs(vector<vector<int>> &a, int r, int c, int comp)
{
    // iterative!
    stack<pair<int, int>> stack;
    stack.push({r, c});

    while (!stack.empty()) {
        auto [r_cur, c_cur] = stack.top();
        stack.pop();

        for (int i = 0; i < 4; ++i) {
            int r_nxt = r_cur + r_dif[i];
            int c_nxt = c_cur + c_dif[i];

            if (r_nxt >= 0 && r_nxt < ROWS && c_nxt >= 0 && c_nxt < COLS) {
                if (a[r_nxt][c_nxt] == comp) {
                    a[r_nxt][c_nxt] = INF;
                    stack.push({r_nxt, c_nxt});
                }
            }
        }
    }
}

int solution(vector<vector<int>> &a)
{
    int result = 0;
    ROWS = (int)a.size(), COLS = (int)a[0].size();

    for (int r = 0; r < ROWS; ++r) {
        for (int c = 0; c < COLS; ++c) {
            if (a[r][c] != INF) {
                int comp = a[r][c];
                a[r][c] = INF;
                dfs(a, r, c, comp);
                ++result;
            }
        }
    }
    return result;
}
