/**
 * https://cses.fi/problemset/task/1069
 */

#include <algorithm>
#include <cstdio>

#define ull unsigned long long

using namespace std;

int main(int argc, char **argv)
{
    int cnt = 0, ans = 0;
    char last = ' ', cur = ' ';

    while (cur = getchar(), cur == 'A' || cur == 'C' || cur == 'G' || cur == 'T') {
        (cur == last) ? cnt++ : cnt = 1;
        ans = max(cnt, ans);
        last = cur;
    }

    printf("%d\n", ans);

    return 0;
}
