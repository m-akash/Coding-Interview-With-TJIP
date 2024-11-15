class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();
        vector< vector<int> > ans; 
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n; i++){
            if(i > 0 and arr[i] == arr[i-1]) {
                continue;
            }
            int left = i + 1;
            int right = n - 1;
            while(left < right) {
                int sum = arr[i] + arr[left] + arr[right];
                if(sum < 0) {
                    left++;
                }
                else if(sum > 0) {
                    right--;
                }
                else {
                    vector<int> temp = {arr[i], arr[left], arr[right]};
                    ans.push_back(temp);
                    left++, right--;
                    while(left < right && arr[left] == arr[left-1]) {
                        left++;
                    }
                    while(left < right && arr[right] == arr[right+1]) {
                        right--;
                    }
                }
            }
        }
        return ans;
    }
};
