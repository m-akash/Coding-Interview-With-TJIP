class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        if (find(nums.begin(), nums.end(), 1) == nums.end()) {
            return 1;
        }
        for (auto& num : nums) {
            num = max(num, 1);
        }
        for (int i = 0; i < n; i++) {
            int index = abs(nums[i]) - 1;
            if (index < n and nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
                break;
            }
        }
        return n + 1;
    }
};
