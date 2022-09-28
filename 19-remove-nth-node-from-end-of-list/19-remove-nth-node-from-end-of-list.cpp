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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* curr = head;
        //calculate length of list
        while(curr != NULL){
            len++;
            curr = curr->next;
        }
      
        //find target node number
        int node_number_from_start = len - n + 1;
        //if it's head, delete this
        if(node_number_from_start == 1){
            return head->next;
        }
        //move to nearest of target node
        curr = head;
        int i=2; 
        while(i< node_number_from_start){
            curr = curr->next;
            i++;
        }
        //update that with next of target
        curr->next = curr->next->next;
        return head;
    }
};