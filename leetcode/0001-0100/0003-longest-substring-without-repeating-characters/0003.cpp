/**
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/
 */

#include <algorithm>
#include <bit>
#include <cassert>
#include <chrono>
#include <cmath>
// #include <ext/pb_ds/assoc_container.hpp>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
// #include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

auto start_time = chrono::high_resolution_clock::now();
auto elapsed_time() -> double
{
    using namespace chrono;
    return static_cast<double>(duration_cast<microseconds>(high_resolution_clock::now() - start_time).count()) / 1e6;
}

#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        size_t ptr = 0;
        size_t res = 0;
        map<char, size_t> map;

        for (size_t i = 0; i < s.size(); ++i) {
            auto &&ch = s[i];
            auto &&it = map.find(ch);

            // repeated!
            if (it != map.end()) {
                if (it->second >= ptr) {
                    res = max(res, i - ptr);
                    ptr = it->second + 1;
                }
                else {
                    // do nothing, because we have skipped this option already
                }
            }
            map[ch] = i;
        }

        return max(res, s.size() - ptr);
    }
};

auto main(int, char **) -> int
{
    Solution s;
    return 0;
}
