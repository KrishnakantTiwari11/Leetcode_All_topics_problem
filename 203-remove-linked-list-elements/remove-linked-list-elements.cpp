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
    void helper(ListNode*prev,ListNode*curr,int val){
        if(!curr){
            return;
        }
        if(curr->val==val){
            prev->next=curr->next;
        }
        helper(curr,curr->next,val);
        if(curr->val==val){
            prev->next=curr->next;
        }
    }
    ListNode* removeElements(ListNode* head, int val) {
        ListNode*dummy=new ListNode(0);
        dummy->next=head;

        helper(dummy,head,val);
        return dummy->next;
    }
};