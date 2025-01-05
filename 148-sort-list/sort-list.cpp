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
    ListNode* sortList(ListNode* head) {
        ListNode*ptr=head;
        vector<int>list;
        while(ptr!=NULL){
            list.push_back(ptr->val);
            ptr=ptr->next;
        }
        sort(list.begin(),list.end());
        ptr=head;
        for(int i=0;i<list.size();i++){
            ptr->val=list[i];
            ptr=ptr->next;
        }
        return head;
    }
};