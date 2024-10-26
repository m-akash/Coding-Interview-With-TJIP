class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size(); vector<vector<int>> ans;
        for(int i = 0; i < n; i++) {
            if(ans.empty() or arr[i][0] > ans.back()[1]) {
                ans.push_back(arr[i]);
            }
            else{
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            }
        }
        return ans;
    }
};

//[[1,3], [2,6], [8,10], [15,18]]
