/**
 * https://leetcode.com/problems/diameter-of-binary-tree/
 */

#include <algorithm>  // reverse, sort, stable_sort
#include <climits>    // INT_MAX
#include <functional> // function
#include <iostream>   // cin, cout
#include <map>
#include <queue> // priority_queue, queue
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

constexpr int MAX = 1e9;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr)
    {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right)
    {
    }
};

class Solution {
public:
    pair<int, int> traverse(TreeNode *node)
    {
        if (node == nullptr) {
            return {0, 0};
        }

        auto [l_con, l_sub] = traverse(node->left);
        auto [r_con, r_sub] = traverse(node->right);

        return pair(max(l_con, r_con) + 1, max(max(l_sub, r_sub), l_con + r_con + 1));
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        auto [con, sub] = traverse(root);
        return max(con, sub) - 1;
    }
};

int main()
{
    Solution s;

    return 0;
}
