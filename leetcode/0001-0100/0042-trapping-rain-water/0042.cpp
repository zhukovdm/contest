/**
 * https://leetcode.com/problems/trapping-rain-water/
 */

#include <algorithm>  // sort, reverse
#include <climits>    // INT_MAX
#include <functional> // function
#include <iostream>   // cin, cout
#include <map>        //
#include <queue>      // priority_queue, queue
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

constexpr int MAX = 1e9;

class Solution {
public:
    int trap(vector<int> &height)
    {
        // we calculate water height *above* [i]

        int N = static_cast<int>(height.size());

        int res = 0;
        int l_max = 0, r_max = 0;
        int l_idx = 0, r_idx = N - 1;

        while (l_idx <= r_idx) {
            if (l_max <= r_max) {
                res += max(0, l_max - height[l_idx]);
                l_max = max(l_max, height[l_idx]);
                ++l_idx;
            }
            else {
                res += max(0, r_max - height[r_idx]);
                r_max = max(r_max, height[r_idx]);
                --r_idx;
            }
        }
        return res;
    }
};

int main()
{
    Solution s;

    return 0;
}
