class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n = arr.size();
        set<vector<int> > st;
        sort(arr.begin(), arr.end());
        if(arr.size() < 4) {
            return {};
        }
        for(int i = 0; i < n - 3; i++) {
            for(int j = i + 1; j < n-2; j++){
                int left = j + 1;
                int right = n - 1;
                while(left < right) {
                    long long sum = (long long)arr[i] + (long long)arr[j] + (long long)arr[left] + (long long)arr[right];
                    if(sum == target) {
                        vector<int> temp = {arr[i], arr[j], arr[left], arr[right]};
                        st.insert(temp);
                        left++, right--;
                    }
                    else if(sum < target) {
                        left++;
                    }
                    else {
                        right--;
                    }
                }
            }
        }
        vector<vector<int>> ans (st.begin(), st.end());
        return ans;
    }
};
