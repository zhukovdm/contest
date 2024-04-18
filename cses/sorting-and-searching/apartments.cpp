/**
 * https://cses.fi/problemset/task/1084
 *
 * The idea is to place applicants greedily, because they stays in appartments
 * forever. Better described at [1, 2].
 *
 * [1] https://www.geeksforgeeks.org/cses-solutions-apartments/
 * [2] https://usaco.guide/problems/cses-1084-apartments/solution
 */

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

using ll = long long;
using ul = unsigned long;

auto main(int argc, char **argv) -> int
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k, ai, bi;
    cin >> n >> m >> k;

    vector<int> a, b;

    while (n--) {
        cin >> ai;
        a.push_back(ai);
    }

    while (m--) {
        std::cin >> bi;
        b.push_back(bi);
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    ul cnt = 0, j = 0;

    for (ul i = 0; i < a.size(); ++i) {

        while (j < b.size() && b[j] < a[i] - k) {
            ++j;
        }
        if (j >= b.size()) {
            break;
        }
        if (a[i] - k <= b[j] && b[j] <= a[i] + k) {
            ++cnt;
            ++j;
        }
    }

    std::cout << cnt << '\n';

    return 0;
}
