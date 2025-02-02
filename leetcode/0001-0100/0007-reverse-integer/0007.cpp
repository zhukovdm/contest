/**
 * https://leetcode.com/problems/reverse-integer/
 */

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int reverse(int x)
    {
        int res = 0;
        while (x > 0) {
            auto dig = x % 10; // preserves sign!
            x /= 10;

            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && dig > +7)) {
                return 0;
            }
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && dig < -8)) {
                return 0;
            }

            res = res * 10 + dig;
        }
        return res;
    }
};

int main()
{
    Solution s;
    cout << s.reverse(123) << endl;

    return 0;
}
