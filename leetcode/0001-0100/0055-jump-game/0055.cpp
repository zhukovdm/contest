/**
 * https://leetcode.com/problems/jump-game/
 */

#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int> &nums)
    {
        int last = static_cast<int>(nums.size()) - 1;
        int l = 0, r = 0;

        while (l <= r && l < last) {
            r = max(r, l + nums[l]);
            if (r >= last) {
                return true;
            }
            ++l;
        }
        return nums.size() == 1;
    }
};
