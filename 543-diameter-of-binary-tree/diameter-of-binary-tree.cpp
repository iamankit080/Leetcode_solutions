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
    int ans=0;
    int diameterOfBinaryTree(TreeNode* root) {
        
        calculateheight(root);
        return ans;
        
    }
        int calculateheight(TreeNode* root){
        if(root==NULL) return 0;
        
        int lh= calculateheight(root->left);
        int rh=calculateheight(root->right);
        
        ans=max(ans,lh+rh);
            return 1+max(lh, rh);
        
    }
};