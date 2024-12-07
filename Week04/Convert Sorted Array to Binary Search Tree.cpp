/*
Complexity Analysis

Time complexity: O(N)
Space Complexity: O(N)
*/
class Solution {
public:
    TreeNode* BuildBST(vector<int>& nums, int L, int R) {
        if (L > R) {
            return nullptr;
        }
        int M = (L + R) / 2;
        auto root = new TreeNode(nums[M]);
        root->left = BuildBST(nums, L, M - 1);
        root->right = BuildBST(nums, M + 1, R);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return BuildBST(nums, 0, n - 1);
    }
};
