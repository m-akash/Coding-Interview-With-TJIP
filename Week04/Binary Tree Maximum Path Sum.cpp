/*
Complexity Analysis

Time Conplexity: O(N)
Space Complexity: O(h)
*/
class Solution {
public:
    int merged_path;
    int findMaxChainSum(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        int left_chain = findMaxChainSum(root->left);
        int right_chain = findMaxChainSum(root->right);
        int max_between_leftNright = max(left_chain, right_chain);
        int result = max(0, max_between_leftNright + root->val);
        merged_path = max(merged_path, left_chain + right_chain + root->val);
        return result;
    }
    int maxPathSum(TreeNode* root) {
        merged_path = INT_MIN / 2;
        findMaxChainSum(root);
        return merged_path;
    }
};
