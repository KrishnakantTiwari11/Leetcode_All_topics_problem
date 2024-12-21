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
        queue<int>q1;
        queue<int>q2;
        ListNode*ptr=head;
        while(ptr!=NULL)
        {
            int temp=ptr->val;
            if(temp<x)
            {
                q1.push(temp);
            }
            else
            {
                q2.push(temp);
            }
            ptr=ptr->next;
        }

        ListNode*newNode=new ListNode(0);
        ListNode*curr=newNode;
        while(!q1.empty())
        {
            int temp=q1.front();
            q1.pop();
            curr->next=new ListNode(temp);
            curr=curr->next;
        }
        while(!q2.empty())
        {
            int temp=q2.front();
            q2.pop();
            curr->next=new ListNode(temp);
            curr=curr->next;
        }
        return newNode->next;
    }
};