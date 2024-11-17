class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy_head = new ListNode(0);
        ListNode* current = dummy_head;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry = 0;
        while (temp1 != NULL or temp2 != NULL) {
            int sum = carry;
            if (temp1) {
                sum += temp1->val;
            }
            if (temp2) {
                sum += temp2->val;
            }
            ListNode* new_node = new ListNode(sum % 10);
            carry = sum / 10;
            current->next = new_node;
            current = current->next;
            if (temp1) {
                temp1 = temp1->next;
            }
            if (temp2) {
                temp2 = temp2->next;
            }
        }
        if (carry) {
            ListNode* new_node = new ListNode(carry);
            current->next = new_node;
        }
        return dummy_head->next;
    }
};
