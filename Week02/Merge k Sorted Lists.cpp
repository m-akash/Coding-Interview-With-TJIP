class Solution {
public:
    ListNode* mergeTwoList(ListNode* list1, ListNode* list2) {
        ListNode* dummy_head = new ListNode(0);
        ListNode* cpy = dummy_head;
        while (list1 and list2) {
            int value1 = list1->val;
            int value2 = list2->val;
            if (value1 < value2) {
                dummy_head->next = new ListNode(value1);
                list1 = list1->next;
                dummy_head = dummy_head->next;
            } else {
                dummy_head->next = new ListNode(value2);
                list2 = list2->next;
                dummy_head = dummy_head->next;
            }
        }
        while (list1) {
            dummy_head->next = new ListNode(list1->val);
            list1 = list1->next;
            dummy_head = dummy_head->next;
        }
        while (list2) {
            dummy_head->next = new ListNode(list2->val);
            list2 = list2->next;
            dummy_head = dummy_head->next;
        }
        return cpy->next;
    }
    ListNode* merger(int L, int R, vector<ListNode*> lists) {
        if (L > R) {
            return NULL;
        }
        if (L == R) {
            return lists[L];
        }
        int MID = (L + R) / 2;
        ListNode* LEFT = merger(L, MID, lists);
        ListNode* RIGHT = merger(MID + 1, R, lists);
        return mergeTwoList(LEFT, RIGHT);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return merger(0, lists.size() - 1, lists);
    }
};
