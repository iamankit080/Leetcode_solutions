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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        
        if (root == NULL) return result;
        
        queue<TreeNode*> qu;
        qu.push(root);
        
        bool lr = true; // Check direction of traversal.
        
        while (!qu.empty()) {
            int size = qu.size();
            vector<int> row(size);
            
            for (int i = 0; i < size; i++) {
                TreeNode* node = qu.front();
                qu.pop();
                
                int index;
                if (lr) 
                    index = i;
                else 
                    index = size - 1 - i;
                
                row[index] = node->val;
                
                if (node->left != NULL) 
                    qu.push(node->left);
                
                if (node->right != NULL) 
                    qu.push(node->right);
            }
            lr = !lr; 
            result.push_back(row); 
        }
        return result;
    }
};
