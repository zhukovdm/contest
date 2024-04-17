/**
 * https://app.codility.com/programmers/lessons/3-time_complexity/tape_equilibrium/
 */

#include <cstdlib>
#include <vector>

using namespace std;

using ll = long long;

auto solution(vector<int> &a) -> int
{
    ll min_sum = 1e18, tot_sum = 0, l_sum = 0;

    for (auto &&item : a) {
        tot_sum += item;
    }

    for (ll i = 0; i < (int)a.size() - 1; ++i) {
        l_sum += a[i];
        ll r_sum = tot_sum - l_sum;
        if (abs(l_sum - r_sum) < min_sum) {
            min_sum = abs(l_sum - r_sum);
        }
    }

    return min_sum;
}
