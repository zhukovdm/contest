/**
 * https://leetcode.com/problems/3sum/
 */

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());

        int N = static_cast<int>(nums.size());

        for (int l = 0; l < N - 2; /* ++l */) {

            if (nums[l] > 0) {
                break;
            }

            int r = N - 1; // right most

            while (r - l > 1) {
                auto diff = -(nums[r] + nums[l]);

                auto i = l + 1;
                auto j = r - 1;

                do {
                    if (diff < nums[l] || diff > nums[r]) {
                        break;
                    }
                    auto m = (i + j) / 2;

                    if (nums[m] == diff) {
                        result.emplace_back(vector<int>{nums[l], nums[m], nums[r]});
                        break;
                    }

                    if (nums[m] < diff) {
                        i = m + 1;
                    }

                    if (nums[m] > diff) {
                        j = m - 1;
                    }
                } while (i <= j);

                do {
                    --r;
                } while (r > 0 && nums[r] == nums[r + 1]);
            }

            do {
                ++l;
            } while (l < N - 2 && nums[l - 1] == nums[l]);
        }

        return result;
    }
};

int main()
{
    Solution s;

    // vector<int> nums{-1, 0, 1, 2, -1, -4};
    // vector<int> nums{3, 0, -2, -1, 1, 2};
    // vector<int> nums{-1, 0, 1, 0};

    vector<int> nums{0, 0, 0, 0};

    auto result = s.threeSum(nums);

    return 0;
}
