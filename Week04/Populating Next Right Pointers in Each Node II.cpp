/*
Complexity Analysis

Time Complexity: O(N)
Space Complexity: O(1)
*/
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return nullptr;
        }
        Node* current = root;
        Node* head = nullptr;
        Node* previous = nullptr;
        while (current != nullptr) {
            while (current != nullptr) {
                if (current->left != nullptr) {
                    if (previous != nullptr) {
                        previous->next = current->left;
                    } else {
                        head = current->left;
                    }
                    previous = current->left;
                }

                if (current->right != nullptr) {
                    if (previous != nullptr) {
                        previous->next = current->right;
                    } else {
                        head = current->right;
                    }
                    previous = current->right;
                }
                current = current->next;
            }
            current = head;
            head = nullptr;
            previous = nullptr;
        }
        return root;
    }
};
