/*
Complexity Analysis

Time Complexity: O(N)
Space Complexity: O(N)
*/
class Solution {
public:
    bool isSymmetric_helper(TreeNode* leftNode, TreeNode* rightNode) {
        if (leftNode == nullptr or rightNode == nullptr) {
            return leftNode == rightNode;
        }
        if (leftNode->val != rightNode->val) {
            return false;
        }
        return isSymmetric_helper(leftNode->left, rightNode->right) and
               isSymmetric_helper(leftNode->right, rightNode->left);
    }

    bool isSymmetric(TreeNode* root) {
        return root == nullptr or isSymmetric_helper(root->left, root->right);
    }
};
