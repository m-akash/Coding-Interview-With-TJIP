/*
Complexity Analysis

Time Complexity: O(N)
Space Complexity: O(N) + recursive stack space
*/
class Solution {
public:
    void InOrderTraversal(TreeNode* root, vector<int>& v) {
        if (root == nullptr) {
            return;
        }
        InOrderTraversal(root->left, v);
        v.push_back(root->val);
        InOrderTraversal(root->right, v);
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v;
        InOrderTraversal(root, v);
        return v[k - 1];
    }
};
