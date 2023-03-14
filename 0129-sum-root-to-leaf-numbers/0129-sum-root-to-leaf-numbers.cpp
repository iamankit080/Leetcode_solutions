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
private:
    void func(TreeNode* root, int &sum, int currNum){
        if( !root->left && !root->right ){
            cout << currNum << endl;
            sum += currNum * 10  + root->val;
            return;
        }
        if( root->left )
            func(root->left, sum, currNum * 10 + root->val);
        if( root->right )
            func(root->right, sum, currNum * 10 + root->val);
    }

public:
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        int currNum = 0;
        func(root, sum, currNum);
        return sum;
    }
};