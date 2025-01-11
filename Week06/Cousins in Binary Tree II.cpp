/*
Complexity Analysis

Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
    TreeNode* replaceValueInTree(TreeNode* root) {
        queue<TreeNode*> Q;
        Q.push(root);
        int cur_lvl_sum = root->val;
        while (!Q.empty()) {
            int next_lvl_sum = 0;
            int n = Q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* current = Q.front();
                Q.pop();
                current->val = cur_lvl_sum - current->val;
                int sibling_sum = (current->left ? current->left->val : 0) +
                                  (current->right ? current->right->val : 0);
                next_lvl_sum += sibling_sum;
                if (current->left) {
                    current->left->val = sibling_sum;
                    Q.push(current->left);
                }
                if (current->right) {
                    current->right->val = sibling_sum;
                    Q.push(current->right);
                }
            }
            cur_lvl_sum = next_lvl_sum;
        }
        return root;
    }
};
