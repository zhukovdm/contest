/**
 * https://cses.fi/problemset/task/1070
 */

#include <algorithm>
#include <iostream>

#define ull unsigned long long

using namespace std;

int n;

void print(int k)
{
    while (k <= n) {
        cout << k << ' ';
        k += 2;
    }
}

int main(int argc, char **argv)
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    if (n == 1) {
        cout << n << '\n';
    }
    else if (n >= 2 && n <= 3) {
        cout << "NO SOLUTION";
    }
    else {
        print(2);
        print(1);
        cout << '\n';
    }
    return 0;
}
