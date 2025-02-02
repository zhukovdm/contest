/**
 * https://leetcode.com/problems/path-sum-ii/
 */

#include <vector>

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
    void find(vector<vector<int>> &result, vector<int> &buffer, TreeNode *node, int rest)
    {
        buffer.push_back(node->val);
        rest -= node->val;

        if (node->left == nullptr && node->right == nullptr && rest == 0) {
            result.emplace_back(buffer);
        }

        if (node->left != nullptr) {
            find(result, buffer, node->left, rest);
        }

        if (node->right != nullptr) {
            find(result, buffer, node->right, rest);
        }

        rest += node->val;
        buffer.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        vector<int> buffer;
        vector<vector<int>> result;

        if (root != nullptr) {
            find(result, buffer, root, targetSum);
        }

        return result;
    }
};
