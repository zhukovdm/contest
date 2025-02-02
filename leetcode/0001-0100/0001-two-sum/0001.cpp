/**
 * https://leetcode.com/problems/two-sum/
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
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> seen;

        for (int i = 0; i < nums.size(); ++i) {
            auto &&num = nums[i];

            auto diff = target - num;
            auto iter = seen.find(diff);

            // doplnek existuje
            if (iter != seen.end()) {
                return vector<int>{iter->second, i};
            }

            // doplnek neexistuje
            else {
                seen[num] = i;
            }
        }

        throw exception(); // unreachable branch
    }
};

auto main(int, char **) -> int
{
    Solution s;
    return 0;
}
