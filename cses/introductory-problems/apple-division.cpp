/**
 * https://cses.fi/problemset/task/1623
 */

#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
using ull = unsigned long long;

ull best = (ull)1e9 * 20 + 1;

auto partite(const vector<ull> &apples, ull l, ull r, size_t i) -> void
{
    if (i < apples.size()) {
        partite(apples, l + apples[i], r, i + 1);
        partite(apples, l, r + apples[i], i + 1);
    }

    else {
        auto candidate = max(l, r) - min(l, r);
        best = (candidate < best) ? candidate : best;
    }
}

auto main(int, char **) -> int
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    size_t n;
    cin >> n;

    vector<ull> v;
    ull l = 0, r = 0;

    while (n--) {
        ull val;
        cin >> val;
        v.push_back(val);
    }

    partite(v, l, r, 0);
    cout << best << '\n';

    return 0;
}
