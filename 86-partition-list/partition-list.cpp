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
    ListNode* partition(ListNode* head, int x) {
        ListNode*l1=new ListNode(0);
        ListNode*l2=new ListNode(0);
        ListNode*l1_ptr=l1;
        ListNode*l2_ptr=l2;
        ListNode*ptr=head;
        while(ptr!=NULL)
        {
            int temp=ptr->val;
            if(temp<x)
            {
                l1_ptr->next=new ListNode(temp);
                l1_ptr=l1_ptr->next;
            }
            else
            {
                l2_ptr->next=new ListNode(temp);
                l2_ptr=l2_ptr->next;

            }
            ptr=ptr->next;
        }
        ListNode*temp_ptr=l2;
        temp_ptr=temp_ptr->next;
        l1_ptr->next=temp_ptr;
        return l1->next;
        }
};