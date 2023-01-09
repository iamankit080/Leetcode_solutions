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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root==NULL) return ans;
        TreeNode *curr=root;
        while(curr!=NULL){
            if(curr->left==NULL){
                ans.push_back(curr->val);
                curr=curr->right;
            }
        else{
            TreeNode *Temp=curr->left;
            while(Temp->right!=NULL && Temp->right!=curr){
                Temp=Temp->right;
            }
            if(Temp->right==NULL){
                Temp->right=curr;
                ans.push_back(curr->val);
                curr=curr->left;
            }
            else
            {
                Temp->right=NULL;
                curr=curr->right;
            }
        }
    }
    return ans;
    }
};