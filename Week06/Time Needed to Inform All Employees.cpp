/*
Complexity Analysis

Time Complexity: O (n)
Space Complexity: O (n)
*/
class Solution {
public:
    unordered_map<int, vector<int>> id_to_manager;
    int ans = 0, mx = 0;
    void dfs(int manager, vector<int>& informTime) {
        mx = max(mx, ans);
        for (auto employee : id_to_manager[manager]) {
            ans += informTime[manager];
            dfs(employee, informTime);
            ans -= informTime[manager];
        }
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        for (int i = 0; i < n; i++) {
            int val = manager[i];
            if (val != -1) {
                id_to_manager[val].push_back(i);
            }
        }
        dfs(headID, informTime);
        return mx;
    }
};
