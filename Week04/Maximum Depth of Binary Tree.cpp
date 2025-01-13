/*
Complexity Analysis

Time Complexity: O(N)
Space Complexity: O(height)
*/
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) {
            return 0;
        }
        int l_mx = maxDepth(root->left);
        int r_mx = maxDepth(root->right);
        return max(l_mx, r_mx) + 1;
    }
};
