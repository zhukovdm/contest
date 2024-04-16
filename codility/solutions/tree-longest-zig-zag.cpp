#include <algorithm>

using namespace std;

struct tree {
    tree *l;
    tree *r;
};

enum class turn { N, L, R };

int solve(tree *tree, turn turn)
{
    int result = 0;
    if (tree) {
        auto l = solve(tree->l, turn::L);
        if (tree->l && turn == turn::R) {
            ++l;
        }

        auto r = solve(tree->r, turn::R);
        if (tree->r && turn == turn::L) {
            ++r;
        }

        result = max(l, r);
    }
    return result;
}

int solution(tree *t)
{
    return solve(t, turn::N);
}
