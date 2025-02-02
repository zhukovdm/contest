/**
 * https://leetcode.com/problems/maximum-subarray/
 */

#include <algorithm> // sort, reverse,
#include <climits>   // INT_MAX,
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

constexpr int MAX = 1e9;

class Solution {
public:
    int maxSubArray(vector<int> &nums)
    {
        int s_cur = -MAX, s_max = -MAX;

        for (int i = 0; i < nums.size(); ++i) {
            auto s_new = nums[i] + ((s_cur == -MAX) ? 0 : s_cur);

            if (s_new < 0) {
                s_max = max(s_max, s_cur);
                s_max = max(s_max, nums[i]);
                s_cur = -MAX;
            }
            else {
                s_cur = s_new;
                s_max = max(s_max, s_new);
            }
        }

        return s_max;
    }
};

int main()
{
    Solution s;
    vector<int> nums{-1, -2, -3};
    // vector<int> nums{5, 4, -1, 7, 8};
    // vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << s.maxSubArray(nums) << endl;

    return 0;
}
