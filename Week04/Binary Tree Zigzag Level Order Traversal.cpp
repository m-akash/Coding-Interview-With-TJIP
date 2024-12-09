/*
Complexity Analysis

Time Complexity: O(N), Where N means total node of the tree.
Space Complexity: O(N), Where N means total node of the tree.
*/
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (root == nullptr) {
            return result;
        }
        queue<TreeNode*> node_queue;
        node_queue.push(root);
        bool leftTOright = true;
        while (!node_queue.empty()) {
            int n = node_queue.size();
            vector<int> row(n);
            for (int i = 0; i < n; i++) {
                TreeNode* node = node_queue.front();
                node_queue.pop();
                int index = leftTOright ? i : n - 1 - i;
                row[index] = node->val;
                if (node->left) {
                    node_queue.push(node->left);
                }
                if (node->right) {
                    node_queue.push(node->right);
                }
            }
            leftTOright = !leftTOright;
            result.push_back(row);
        }
        return result;
    }
};
