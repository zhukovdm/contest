/**
 * https://cses.fi/problemset/task/1640
 */

#include <algorithm>
#include <chrono>
#include <climits>
#include <ext/pb_ds/assoc_container.hpp>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class safe_hash {
public:
    static auto splitmix64(uint64_t x) -> uint64_t
    {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    auto operator()(uint64_t x) const -> std::size_t // !
    {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
template <typename K, typename V>
using safe_map = __gnu_pbds::gp_hash_table<K, V, safe_hash>;
template <typename K>
using safe_set = __gnu_pbds::gp_hash_table<K, __gnu_pbds::null_type, safe_hash>;

int main()
{
    using namespace std;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt, trg, itm;
    safe_map<int, int> map;

    cin >> cnt >> trg;

    for (int i = 1; i <= cnt; ++i) {
        cin >> itm;
        int dif = trg - itm;

        auto it = map.find(dif);

        if (it != map.end()) {
            cout << it->second << ' ' << i << '\n';
            return 0;
        }
        else {
            map[itm] = i;
        }
    }

    cout << "IMPOSSIBLE" << '\n';

    return 0;
}
