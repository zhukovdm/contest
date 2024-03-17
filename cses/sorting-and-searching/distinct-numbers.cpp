/**
 * https://cses.fi/problemset/task/1621
 */

#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ul = unsigned long;

constexpr char EOL = '\n';

auto main(int argc, char **argv) -> int
{
    ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::set<int> c;

    while (n--) {
        int x;
        std::cin >> x;
        c.insert(x);
    }

    std::cout << c.size() << EOL;

    return 0;
}
