class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(); 
        int cnt = 0; int element;
        for(int i = 0; i < n; i++) {
            if(cnt == 0) {
                cnt = 1;
                element = nums[i];
            }
            else if(element == nums[i]) {
                cnt++;
            }
            else {
                cnt--;
            }
        }
        int appears = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == element) {
                appears++;
            }
        }
        if(appears > n/2) {
            return element;
        }
        return -1;
    }
};
