/**
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 1;

        for (int j = i; j < nums.size(); ++j) {
            if (nums[j] > nums[i - 1]) {
                nums[i] = nums[j];
                ++i;
            }
        }

        return i;
    }
};

int main()
{
    return 0;
}
