class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head) {
        ListNode* current = head;
        ListNode* previous = nullptr;
        while (current) {
            ListNode* next_ref = current->next;
            current->next = previous;
            previous = current;
            current = next_ref;
        }
        return previous;
    }

    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* reversed = reverseLinkedList(slow);
        int max_sum = 0;
        ListNode* h1 = head;
        ListNode* h2 = reversed;
        while (h2) {
            max_sum = max(h1->val + h2->val, max_sum);
            h1 = h1->next;
            h2 = h2->next;
        }
        return max_sum;
    }
};
