class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector< vector<int> > ans;
        sort(arr.begin(), arr.end());
        for(int i = 0; i < n; i++) {
            if(i > 0 and arr[i] == arr[i-1]) {
                continue;
            }
            for(int j = i + 1; j < n; j++) {
                if(j > i + 1 and arr[j] == arr[j-1]) {
                    continue;
                }
                int left = j + 1;
                int right = n - 1;
                while(left < right) {
                    long long sum = (long long)arr[i] + (long long)arr[j] + (long long)arr[left] + (long long)arr[right];
                    if(sum == target) {
                        vector<int> temp = {arr[i], arr[j], arr[left], arr[right]};
                        ans.push_back(temp);
                        left++, right--;
                        while(left < right and arr[left] == arr[left-1]) {
                            left++;
                        }
                        while(left < right and arr[right] == arr[right+1]) {
                            right--;
                        }
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
        return ans;
    }
};
