/**
 * https://cses.fi/problemset/task/2165
 */

#include <iostream>
#include <vector>

#define ll long long
#define ull unsigned long long

void hanoi(int from, int to, int stones)
{
    if (stones > 0) {
        int next = 6 - from - to;
        hanoi(from, next, stones - 1);
        std::cout << from << ' ' << to << '\n';
        hanoi(next, to, stones - 1);
    }
}

int main(int argc, char **argv)
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int stones;
    std::cin >> stones;

    std::cout << (1 << stones) - 1 << '\n';
    hanoi(1, 3, stones);

    return 0;
}
