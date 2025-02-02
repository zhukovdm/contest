/**
 * https://leetcode.com/problems/palindrome-number/
 */

#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <functional>
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

using namespace std;

#ifdef LOCAL
#include "../../algo/debug.hpp"
#else
#define debug(...) 42
#endif

class Solution {
public:
    bool isPalindrome(int x)
    {
        long long a = 0, b = x;
        if (x < 0) {
            return false;
        }
        if (x < 10) {
            return true;
        }
        while (x) {
            a = a * 10 + x % 10;
            x /= 10;
        }
        return a == b;
    }
};

auto main(int, char **) -> int
{
    Solution s;

    cout << s.isPalindrome(101) << endl;
    cout << s.isPalindrome(4224) << endl;

    return 0;
}
