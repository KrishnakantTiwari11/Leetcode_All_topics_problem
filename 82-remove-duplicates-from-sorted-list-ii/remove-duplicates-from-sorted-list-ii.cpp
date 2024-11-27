class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }
        if (head->next == NULL) {
            return head;
        }

        ListNode* dummy = new ListNode(0, head);
        ListNode* res = dummy;
        ListNode* curr = head;

        while (curr != NULL) {
            if (curr->next == NULL || curr->val != curr->next->val) {
                res->next = curr;
                res = res->next;
            }
            else
            {
            while (curr->next != NULL && curr->val == curr->next->val) {
                curr = curr->next;
            }
            }
            curr = curr->next;
        }
        res->next = NULL;
        return dummy->next;
    }
};
