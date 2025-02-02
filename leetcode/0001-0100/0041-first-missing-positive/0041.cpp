/**
 * https://leetcode.com/problems/first-missing-positive/
 *
 * The idea of this problem is to look at a i-th number and put it to the
 * index it is supposed to be found (possibly later). Then, the number on
 * that index should be moved similarly. Each number could be moved only
 * once, and we can look at the number max. 2 times.
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void tryFix(vector<int> &nums, int v)
    {
        int n = nums.size();

        while (1 <= v && v <= n && nums[v - 1] != v) {
            auto tmp = nums[v - 1];
            nums[v - 1] = v;
            v = tmp;
        }
    }

    int firstMissingPositive(vector<int> &nums)
    {
        // due to the task definition, not possible to --nums[i];

        for (int i = 0; i < nums.size(); ++i) {
            tryFix(nums, nums[i]);
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return nums.size() + 1;
    }
};
