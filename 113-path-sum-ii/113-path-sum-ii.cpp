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
     vector<vector<int>>ans;
    
    void inorder(TreeNode*root,vector<int>&path, int& sum, int & targetSum){
        if(root==NULL) return;
        //operate on root
        //update sum
        sum+= root->val;
        path.push_back(root->val);
        //check if we got a valid path 
        if(sum== targetSum and root->left == NULL and root ->right ==NULL){
            ans.push_back(path);
            } else { //go to left and right children
            
        inorder(root->left,path,sum,targetSum);
            
        inorder(root->right,path,sum,targetSum);
        }
        //returning from current root, remove it from path and sum
        path.pop_back();
        sum-=root->val;
        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector <int>path;
        int sum =0;
        inorder (root, path, sum, targetSum);
            return ans;
        
    }
};