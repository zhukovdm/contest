/**
 * https://leetcode.com/problems/generate-parentheses/
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void generate(vector<string> &result, string current, size_t cnt, size_t acc)
    {
        if (cnt == 0 && acc == 0) {
            result.push_back(current);
        }

        // can add (
        if (cnt > 0) {
            generate(result, current + '(', cnt - 1, acc + 1);
        }

        // can add )
        if (acc > 0) {
            generate(result, current + ')', cnt, acc - 1);
        }
    }

    vector<string> generateParenthesis(int n)
    {
        vector<string> result;
        generate(result, "", n, 0);

        return result;
    }
};

int main()
{
    Solution s;

    auto result = s.generateParenthesis(3);

    for (auto &&item : result) {
        cout << item << endl;
    }

    return 0;
}
