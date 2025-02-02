/**
 * https://leetcode.com/problems/binary-tree-tilt/
 */

#include <cmath>

using namespace std;

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
    pair<int, int> solveTilt(TreeNode *node)
    {
        if (node == nullptr) {
            return {0, 0};
        }
        auto [l_sum, l_tilt] = solveTilt(node->left);
        auto [r_sum, r_tilt] = solveTilt(node->right);

        return {l_sum + r_sum + node->val, abs(l_sum - r_sum) + l_tilt + r_tilt};
    }

    int findTilt(TreeNode *root)
    {
        auto [sum, tilt] = solveTilt(root);
        return tilt;
    }
};
