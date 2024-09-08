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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int countNodes = 0;
        ListNode* dummy = head;
        while (dummy != nullptr) {
            countNodes++;
            dummy = dummy->next;
        }
        
        int partSize = countNodes / k;
        int remainder = countNodes % k;

        vector<ListNode*> result(k, nullptr);
        ListNode* current = head;
        
        for (int i = 0; i < k; ++i) {
            result[i] = current;
            int currentPartSize = partSize + (remainder > 0 ? 1 : 0);
            remainder--;

            for (int j = 1; j < currentPartSize && current != nullptr; ++j) {
                current = current->next;
            }
            
            if (current != nullptr) {
                ListNode* nextPart = current->next;
                current->next = nullptr;
                current = nextPart;
            }
        }
        
        return result;
    }
};
