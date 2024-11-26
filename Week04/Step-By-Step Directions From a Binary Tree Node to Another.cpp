/*
Complexity Analysis

Time Complexity: O(n) + O(h) = O(n) (since, h <= n)
Space Complexity: O(h)
*/
class Solution {
public:
    bool find_path(TreeNode* root, int val, string& path) {
        if (root->val == val) {
            return true;
        }
        if (root->left and find_path(root->left, val, path)) {
            path.push_back('L');
        } else if (root->right and find_path(root->right, val, path)) {
            path.push_back('R');
        }
        return !path.empty();
    }
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string start_path, dest_path;
        find_path(root, startValue, start_path);
        find_path(root, destValue, dest_path);
        while (!start_path.empty() and !dest_path.empty() and
               start_path.back() == dest_path.back()) {
            start_path.pop_back();
            dest_path.pop_back();
        }
        return string(start_path.size(), 'U') + string(rbegin(dest_path), rend(dest_path));
    }
};
