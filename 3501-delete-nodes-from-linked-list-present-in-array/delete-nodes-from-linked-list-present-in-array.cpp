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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>set(nums.begin(),nums.end());
        ListNode*dummy=new ListNode(0);
        dummy->next=head;
        ListNode*prevptr=dummy;
        ListNode*currptr=head;
        while(currptr!=NULL)
        {
            if(set.count(currptr->val))
            {
                prevptr->next=currptr->next;
                currptr=prevptr->next;
            }
            else
            {
               prevptr=currptr;
               currptr=currptr->next;
                
            }
        }
        ListNode*res=dummy->next;
        delete dummy;
        return res;
        
    }
};