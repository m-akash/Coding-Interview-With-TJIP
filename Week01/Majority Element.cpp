class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(); int MajorityElement;
        map<int, int> CountMajority;
        for(int i = 0; i < n; i++) {
            CountMajority[nums[i]]++;
        }
        for(auto it : CountMajority) {
            if(it.second > n/2){
                MajorityElement = it.first;
            }
        }
        return MajorityElement;
    }
};
