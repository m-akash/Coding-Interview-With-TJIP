class MyLinkedList {
private:
    class ListNode {
    public:
        int val;
        ListNode* next;
        ListNode(int _val = 0, ListNode* _next = nullptr) {
            val = _val;
            next = _next;
        }
    };
    int len;
    ListNode* dummy_head;

public:
    MyLinkedList() {
        len = 0;
        dummy_head = new ListNode();
    }

    int get(int index) {
        if (index < 0 or index >= len) {
            return -1;
        }
        ListNode* copy_head = dummy_head->next;
        while (index--) {
            copy_head = copy_head->next;
        }
        return copy_head->val;
    }

    void addAtHead(int val) { addAtIndex(0, val); }

    void addAtTail(int val) { addAtIndex(len, val); }

    void addAtIndex(int index, int val) {
        if (index > len) {
            return;
        }
        ListNode* copy_head = dummy_head;
        while (index--) {
            copy_head = copy_head->next;
        }
        ListNode* block = new ListNode(val, copy_head->next);
        copy_head->next = block;
        len++;
    }

    void deleteAtIndex(int index) {
        if (index >= len or index < 0) {
            return;
        }
        ListNode* copy_head = dummy_head;
        while (index--) {
            copy_head = copy_head->next;
        }
        ListNode* candidate = copy_head->next;
        copy_head->next = copy_head->next->next;
        delete (candidate);
        len--;
    }
};
