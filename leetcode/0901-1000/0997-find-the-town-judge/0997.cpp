/**
 * https://leetcode.com/problems/find-the-town-judge/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> fr_count(1001, 0);
        vector<int> to_count(1001, 0);

        for (auto &&pair : trust) {
            ++fr_count[pair[0]];
            ++to_count[pair[1]];
        }

        int cand_ord = -1;
        int cand_cnt = 0;

        for (int i = 1; i < n + 1; ++i) {
            if (fr_count[i] == 0 && to_count[i] == n - 1) {
                cand_ord = i;
                ++cand_cnt;
            }
        }

        return (cand_cnt == 1) ? cand_ord : -1;
    }
};
