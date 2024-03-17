/**
 * https://cses.fi/problemset/task/1083
 */

#include <iostream>

using ull = unsigned long long;

using namespace std;

int main(int argc, char *argv[])
{
    ull n;
    cin >> n;
    ull sum = (n * (n + 1)) >> 1;
    while (n > 1) {
        ull temp;
        cin >> temp;
        sum -= temp;
        --n;
    }
    cout << sum << '\n';
}
