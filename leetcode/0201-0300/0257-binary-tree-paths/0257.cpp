/**
 * https://leetcode.com/problems/binary-tree-paths/
 */

#include <iostream>
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
    void construct(vector<string> &result, vector<TreeNode *> &buffer, TreeNode *node)
    {
        buffer.push_back(node);

        // leaf

        if (node->left == nullptr && node->right == nullptr) {
            string path;
            path += to_string(buffer[0]->val);

            for (int i = 1; i < buffer.size(); ++i) {
                path += "->" + to_string(buffer[i]->val);
            }

            result.emplace_back(move(path));
        }

        else {
            if (node->left != nullptr) {
                construct(result, buffer, node->left);
            }
            if (node->right != nullptr) {
                construct(result, buffer, node->right);
            }
        }

        buffer.pop_back();
    }

    vector<string> binaryTreePaths(TreeNode *root)
    {
        vector<string> result;
        vector<TreeNode *> buffer;

        if (root != nullptr) {
            construct(result, buffer, root);
        }

        return result;
    }
};

int main()
{
    Solution s;

    auto n0 = new TreeNode(1);
    auto n1 = new TreeNode(2);
    auto n2 = new TreeNode(3);
    auto n3 = new TreeNode(5);

    n0->left = n1;
    n0->right = n2;
    n1->right = n3;

    auto result = s.binaryTreePaths(n0);

    for (auto &&path : result) {
        cout << path << endl;
    }

    return 0;
}
