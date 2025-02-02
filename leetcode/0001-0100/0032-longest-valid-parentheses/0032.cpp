/**
 * https://leetcode.com/problems/longest-valid-parentheses/
 *
 * Explain!
 */

#include <algorithm>
#include <cassert>
#include <chrono>
#include <cmath>
#include <ext/pb_ds/assoc_container.hpp>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <memory>
#include <optional>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

#ifdef LOCAL
#include "algo/debug.hpp"
#else
#define debug(...) 42
#endif

class Solution {
public:
    void clean_stack(int &res, stack<pair<int, int>> &valid)
    {
        while (!valid.empty()) {
            auto [l, r] = valid.top();
            res = max(res, r - l + 1);
            valid.pop();
        }
    }

    int longestValidParentheses(string s)
    {
        int res = 0;
        stack<int> paren;
        stack<pair<int, int>> valid;

        for (int i = 0; i < (int)s.size(); ++i) {
            auto c = s[i];

            if (c == '(') {
                paren.push(i);
            }
            // attempt to close an open paren
            else {
                // broken sequence
                if (paren.empty()) {
                    clean_stack(res, valid);
                }
                // pairing is found!
                else {
                    auto l_new = paren.top();
                    auto r_new = i;
                    paren.pop();

                    // try merge two intervals
                    while (true) {
                        if (valid.empty()) {
                            break;
                        }
                        auto p = valid.top(); // copy top

                        // contains or neighbor ~> merge
                        if (p.first == l_new + 1 && p.second == r_new - 1 || p.second + 1 == l_new) {
                            valid.pop();
                            l_new = min(p.first, l_new);
                            r_new = max(p.second, r_new);
                        }
                        // no merge
                        else {
                            break;
                        }
                    }
                    valid.push({l_new, r_new});
                }
            }
        }

        clean_stack(res, valid);
        return res;
    }
};

auto main(int, char const *[]) -> int
{
    Solution s;

    std::cout << s.longestValidParentheses("((())())") << std::endl;
    std::cout << s.longestValidParentheses("(()") << std::endl;
    std::cout << s.longestValidParentheses(")()())") << std::endl;
    std::cout << s.longestValidParentheses("") << std::endl;

    return 0;
}
