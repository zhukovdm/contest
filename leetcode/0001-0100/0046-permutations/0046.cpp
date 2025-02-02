/**
 * https://leetcode.com/problems/permutations/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void perm(vector<vector<int>> &result, vector<int> &permutation, vector<int> nums)
    {
        if (nums.size() == 0) {
            result.push_back(permutation);
        }

        else {
            for (int i = 0; i < nums.size(); ++i) {
                permutation.push_back(nums[i]);

                vector<int> next;
                next.insert(next.end(), nums.begin(), nums.begin() + i);
                next.insert(next.end(), nums.begin() + i + 1, nums.end());

                perm(result, permutation, next);
                permutation.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<int> permutation;
        vector<vector<int>> result;
        perm(result, permutation, nums);

        return result;
    }
};

int main()
{
    vector<int> nums{1, 2, 3};

    Solution s;
    auto result = s.permute(nums);

    cout << result[0][0] << endl;

    return 0;
}
