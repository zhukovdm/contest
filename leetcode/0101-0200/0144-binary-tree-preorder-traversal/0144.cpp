/**
 * https://leetcode.com/problems/binary-tree-preorder-traversal/
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
    void traverse(vector<int> &result, TreeNode *node)
    {
        if (node != nullptr) {
            result.push_back(node->val);
            traverse(result, node->left);
            traverse(result, node->right);
        }
    }

    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> result;
        traverse(result, root);
        return result;
    }
};
