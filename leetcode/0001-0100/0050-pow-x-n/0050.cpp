/**
 * https://leetcode.com/problems/powx-n/
 */

#include <algorithm>  // reverse, sort, stable_sort
#include <climits>    // INT_MAX
#include <functional> // function
#include <iostream>   // cin, cout
#include <map>
#include <queue> // priority_queue, queue
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

constexpr int MAX = 1e9;

template <typename T>
auto pow(T a, long long b) -> T
{
    assert(b >= 0);
    T r = 1;
    while (b) {
        if (b & 1)
            r *= a;
        b >>= 1;
        a *= a;
    }
    return r;
}

class Solution {
public:
    double myPow(double x, int n)
    {
        return pow(x, n);
    }
};

int main()
{
    Solution s;

    return 0;
}
