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
    ListNode*divide(ListNode*head){
        if(!head || !head->next){
            return head;
        }
        ListNode*slow=head;
        ListNode*fast=head->next;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode*mid=slow->next;
        slow->next=NULL;
        return merge(divide(head),divide(mid));
    }
    ListNode*merge(ListNode*l1,ListNode*l2){
        ListNode dummy(0);
        ListNode*tail=&dummy;
        while(l1 && l2){
          if(l1->val<=l2->val){
            tail->next=l1;
            tail=tail->next;
            l1=l1->next;
          }else{
             tail->next=l2;
             tail=tail->next;
             l2=l2->next;
          }
        }
        while(l1){
            tail->next=l1;
            tail=tail->next;
            l1=l1->next;
        }
        while(l2){
            tail->next=l2;
            tail=tail->next;
            l2=l2->next;
        }
        return dummy.next;
    }
    ListNode* sortList(ListNode* head) {
       return divide(head);
    }
};