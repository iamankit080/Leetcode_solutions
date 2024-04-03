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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>answer;
        inorder(root, answer);
        return answer; 
    }
    
    
    void inorder(TreeNode* root, vector<int>& answer){
        if(root==NULL) return;
        inorder(root->left, answer);
        answer.push_back(root->val);
        inorder(root->right, answer);
    }
};