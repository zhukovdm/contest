/**
 * https://app.codility.com/programmers/lessons/3-time_complexity/perm_missing_elem/
 */

#include <vector>

using namespace std;

using ll = long long;

int solution(vector<int> &a)
{
    ll N = (ll)a.size();
    ll result = (N + 2) * (N + 1) / 2;
    for (auto &&item : a) {
        result -= item;
    }
    return result;
}
