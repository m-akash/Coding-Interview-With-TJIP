/*
Complexity Analysis

Time Complexity: O(N)
Space Complexity: O(N)
*/
class Solution {
public:
    bool isValidBSTHelper(TreeNode* root, TreeNode* low, TreeNode* high) {
        if (root == nullptr) {
            return true;
        }
        if ((low and root->val <= low->val) or
            (high and root->val >= high->val)) {
            return false;
        }
        bool left_status = isValidBSTHelper(root->left, low, root);
        bool right_status = isValidBSTHelper(root->right, root, high);
        return left_status and right_status;
    }
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, nullptr, nullptr);
    }
};
