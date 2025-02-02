/**
 * https://leetcode.com/problems/zigzag-conversion/
 */

#include <iostream>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    bool within_bounds(int n, int i)
    {
        return 0 <= i && i < n;
    }

    string convert(string s, int numRows)
    {
        int n = s.size();
        string result;

        if (numRows == 1) {
            return s;
        }

        int step = 2 * numRows - 2;

        for (int row = 0; row < numRows; ++row) {
            for (int base_idx = 0; base_idx < n + step; base_idx += step) {
                auto l_idx = base_idx - row;
                auto r_idx = base_idx + row;

                if (row == 0 && within_bounds(n, base_idx)) {
                    result += s[base_idx];
                }
                else if (row == numRows - 1) {
                    if (r_idx < n) {
                        result += s[r_idx];
                    }
                }
                else // 0 < i && i < numRows - 1
                {
                    if (within_bounds(n, l_idx)) {
                        result += s[l_idx];
                    }
                    if (within_bounds(n, r_idx)) {
                        result += s[r_idx];
                    }
                }
            }
        }

        return result;
    }
};

int main()
{
    Solution s;
    cout << s.convert("PAYPALISHIRING", 3) << endl;
    cout << s.convert("ABCD", 3) << endl;

    return 0;
}
