class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size(); vector<int> ans(n, 1);
        for(int i = 1; i < n; i++) {
            ans[i] = ans[i-1] * arr[i-1];
        }
        int suffix = 1;
        for(int i = n-2; i >= 0; i--) {
           suffix *= arr[i+1];
           ans[i] *= suffix;
        }   
        return ans;
    }
};
