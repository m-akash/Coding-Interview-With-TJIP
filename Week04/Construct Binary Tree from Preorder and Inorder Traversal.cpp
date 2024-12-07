/*
Complexity Analysis

Time Complexity: O(N)
Space Complexity: O(N)
*/
class Solution {
public:
    TreeNode* buildTree_helper(vector<int>& preorder, int pre_start, int pre_end, vector<int>& inorder, int in_start, int in_end, map<int, int>& in_map) {
        if (pre_start > pre_end or in_start > in_end) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[pre_start]);
        int inorder_root = in_map[root->val];
        int nums_left = inorder_root - in_start;
        root->left = buildTree_helper(preorder, pre_start + 1, pre_start + nums_left, inorder, in_start, inorder_root - 1, in_map);
        root->right = buildTree_helper(preorder, pre_start + nums_left + 1, pre_end, inorder, inorder_root + 1, in_end, in_map);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> in_map;
        for (int i = 0; i < inorder.size(); i++) {
            in_map[inorder[i]] = i;
        }
        TreeNode* root = buildTree_helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, in_map);
        return root;
    }
};
