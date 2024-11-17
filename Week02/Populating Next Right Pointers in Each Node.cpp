class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return nullptr;
        }
        queue<Node*> q;
        q.push(root);
        while (size(q)) {
            Node* rightNode = nullptr;
            for (int i = size(q); i; i--) {
                auto current = q.front();
                q.pop();
                current->next = rightNode;
                rightNode = current;
                if (current->right) {
                    q.push(current->right);
                    q.push(current->left);
                }
            }
        }
        return root;
    }
};
