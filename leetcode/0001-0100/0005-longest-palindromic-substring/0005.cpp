/**
 * https://leetcode.com/problems/longest-palindromic-substring/
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
    string manacher(const string &s, vector<int> &counts)
    {
        int l = 1, r = 1; // boundaries
        int l_max = 1, r_max = 1;

        for (int i = 1; i <= s.size() - 1; ++i) {
            counts[i] = max(0, min(r - i, counts[l + r - i])); // compare to the mirror and bounds

            while (s[i - counts[i]] == s[i + counts[i]]) {
                ++counts[i];
            }

            if (i + counts[i] > r) {
                l = i - counts[i];
                r = i + counts[i];
            }

            if (r - l > r_max - l_max) {
                l_max = l;
                r_max = r;
            }
        }

        return string(s.begin() + l_max + 1, s.begin() + r_max);
    }

    string longestPalindrome(string s)
    {
        string input("^");
        for (auto letter : s) {
            input += '#';
            input += letter;
        }
        input += "#$";

        vector<int> counts(input.size(), 0);

        auto longest = manacher(input, counts);

        string result;
        for (auto &&letter : longest) {
            if (letter != '#') {
                result.push_back(letter);
            }
        }

        return result;
    }
};

auto main(int, char **) -> int
{
    Solution s;
    return 0;
}
