/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int longestZigZag(TreeNode* root) {
        int result = 0;
        dfs(root, &result);
        return result;
    }

    pair<int, int> dfs(TreeNode* node, int *result) {
        if (!node) {
            return {-1, -1};
        }
        const auto& left = dfs(node->left, result);
        const auto& right = dfs(node->right, result);
        *result = max({*result, left.second + 1, right.first + 1});
        return {left.second + 1, right.first + 1};
    }    
};