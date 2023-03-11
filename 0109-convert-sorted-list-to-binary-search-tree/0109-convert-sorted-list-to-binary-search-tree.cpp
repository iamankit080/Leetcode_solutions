/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* func(ListNode* leftHead, ListNode* rightHead){
        if( leftHead == rightHead ) return NULL;

        ListNode* slowPtr = leftHead;
        ListNode* fastPtr = leftHead;

        while( fastPtr != rightHead && fastPtr->next != rightHead ){
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }

        TreeNode* root = new TreeNode(slowPtr->val);
        root->left = func(leftHead, slowPtr);
        root->right = func(slowPtr->next, rightHead);
        return root;
    }

public:
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* rootNode = func(head, NULL);
        return rootNode;
    }
};