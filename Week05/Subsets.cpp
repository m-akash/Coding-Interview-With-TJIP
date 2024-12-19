/*
Complexity Analysis

Time Complexity: O(N * (2^N))
Space Complexity: O(N * (2^N))
*/
class Solution {
public:
    vector<vector<int>> ans;
    void generateSubset(vector<int>& nums, int current, vector<int> temp) {
        if (current == nums.size()) {
            ans.push_back(temp);
            return;
        }
        generateSubset(nums, current + 1, temp);
        temp.push_back(nums[current]);
        generateSubset(nums, current + 1, temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        generateSubset(nums, 0, temp);
        return ans;
    }
};
