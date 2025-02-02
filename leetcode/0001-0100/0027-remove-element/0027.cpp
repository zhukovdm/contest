/**
 * https://leetcode.com/problems/remove-element/
 */

#include <vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int> &nums, int val)
    {
        int idx = 0;

        for (int i = idx; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[idx++] = nums[i];
            }
        }

        return idx;
    }
};
