/**
 * https://leetcode.com/problems/valid-parentheses/
 */

#include <map>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s)
    {
        stack<char> stack;
        map<char, char> dict{
            {')', '('},
            {'}', '{'},
            {']', '['},
        };

        for (auto &&c : s) {
            if (c == ')' || c == '}' || c == ']') {
                if (stack.empty() || stack.top() != dict[c]) {
                    return false;
                }
                stack.pop();
            }
            else {
                stack.push(c);
            }
        }
        return stack.empty();
    }
};
