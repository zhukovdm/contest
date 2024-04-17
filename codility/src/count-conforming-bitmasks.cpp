/**
 * https://app.codility.com/programmers/trainings/9/count_conforming_bitmasks/
 */

#include <vector>

using namespace std;

int count(int n)
{
    int cnt = 0;
    for (int i = 0; i < 30; ++i) {
        cnt = ((n >> i) & 1) ? cnt + 1 : cnt;
    }
    return 1 << (30 - cnt);
}

int solution(int A, int B, int C)
{
    vector<int> v{A, B, C, A | B, A | C, B | C, A | B | C};
    for (auto &&item : v)
        item = count(item);
    return v[0] + v[1] + v[2] - v[3] - v[4] - v[5] + v[6];
}
