class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = new ListNode(0, head);
        ListNode* current_slow = slow;
        ListNode* fast = slow;
        while (n--) {
            fast = fast->next;
        }
        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next;
        }
        auto remove_node = slow->next;
        slow->next = slow->next->next;
        delete (remove_node);
        return current_slow->next;
    }
};
