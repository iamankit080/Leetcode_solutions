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
string solve(TreeNode* root,   vector<TreeNode*>  &v, unordered_map<string,int> &m){
   
   if(!root){
       return "#";
   }
   string left=solve(root->left,v,m);
   string right=solve(root->right,v,m);
   string s=left+","+right+","+to_string(root->val);
   if(m[s]==1) v.push_back(root);
   m[s]++;
   return s;
}
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> v;
        unordered_map<string,int> m;
        solve (root,v,m);

        return v;
    }
};