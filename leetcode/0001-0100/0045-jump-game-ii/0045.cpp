/**
 * https://leetcode.com/problems/jump-game-ii/
 */

#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int> &nums)
    {
        // 2-pointer approach in O(n)

        int last = nums.size() - 1;
        int l = 0, r = 0, step = 0;

        while (l < last) {
            ++step;
            int nxt_r = 0;

            for (int i = l; i <= r; ++i) {
                nxt_r = max(nxt_r, i + nums[i]);

                if (nxt_r >= last) {
                    return step;
                }
            }
            l = r + 1;
            r = nxt_r;
        }
        return step;
    }
};

int main()
{
    //
    Solution s;
    vector<int> input{2, 3, 1, 1, 4};

    auto result = s.jump(input);

    cout << result << endl;

    return 0;
}
