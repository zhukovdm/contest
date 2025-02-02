/**
 * https://leetcode.com/problems/container-with-most-water/
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height)
    {
        int a_max = 0;
        int l_idx = 0, r_idx = height.size() - 1;

        while (l_idx < r_idx) {
            a_max = max(a_max, (r_idx - l_idx) * min(height[l_idx], height[r_idx]));
            (height[l_idx] < height[r_idx]) ? ++l_idx : --r_idx;
        }

        return a_max;
    }
};

int main(int argc, char **argv)
{
    return 0;
}
