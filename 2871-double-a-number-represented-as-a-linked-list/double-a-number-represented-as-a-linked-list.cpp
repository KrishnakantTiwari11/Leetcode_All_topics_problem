class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        string numberStr = "";
        ListNode* ptr = head;

        while (ptr) {
            numberStr += to_string(ptr->val);
            ptr = ptr->next;
        }

        string resultStr = "";
        int carry = 0;

        for (int i = numberStr.size() - 1; i >= 0; --i) {
            int digit = (numberStr[i] - '0') * 2 + carry;
            carry = digit / 10;
            resultStr += (digit % 10) + '0';
        }

        if (carry > 0) {
            resultStr += carry + '0';
        }

        reverse(resultStr.begin(), resultStr.end());

        ListNode* dummy = new ListNode(0);
        ListNode* newNode = dummy;

        for (char c : resultStr) {
            newNode->next = new ListNode(c - '0');
            newNode = newNode->next;
        }

        return dummy->next;
    }
};
