/*
Complexity Analysis

Time Complexity: O(n), Here n is the size of preorder.
Space Complexity: O(h)
*/
class Solution {
public:
    bool isValidPreorder(vector<int>& preorder, int& indx, int low, int high) {
        if (indx == preorder.size()) {
            return true;
        }
        int root = preorder[indx];
        if (root <= low or root >= high) {
            return false;
        }
        indx++;
        bool left_status = isValidPreorder(preorder, indx, low, root);
        bool right_status = isValidPreorder(preorder, indx, root, high);
        return left_status or right_status;
    }
    bool verifyPreorder(vector<int>& preorder) {
        int indx = 0;
        return isValidPreorder(preorder, indx, INT_MIN, INT_MAX);
    }
};
