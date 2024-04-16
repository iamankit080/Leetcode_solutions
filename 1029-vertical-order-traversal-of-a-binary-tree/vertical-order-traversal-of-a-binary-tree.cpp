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
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int,int>>> qu;
        
        qu.push({root,{0,0}});
        
        while(!qu.empty()){
            auto p=qu.front();
            qu.pop();
            
            TreeNode* node=p.first;
            int x=p.second.first;
            int y=p.second.second;
            
            mp[x][y].insert(node->val); //insert value at (x,y) coordinates in mp.
            
            if(node->left){
                qu.push({node->left,{x-1,y+1}});
            }
            
            if(node->right){
                qu.push({node->right,{x+1,y+1}});
            }
        }
        
        vector<vector<int>>ans;
        for(auto p: mp){
            vector<int>column;
            
            for(auto q: p.second){
                column.insert(column.end(),q.second.begin(),q.second.end());
                
            }
            ans.push_back(column);
        }
        return ans;
        
    }
};