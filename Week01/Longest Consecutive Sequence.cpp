class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        unordered_set<int> st; int n = arr.size();
        int longestSequence = 1;
        if(n == 0) {
            return 0;
        }
        for(int i = 0; i < n; i++) {
            st.insert(arr[i]);
        }
        for(auto it : st) {
            if(st.find(it - 1) == st.end()) {
                int cnt = 1;
                int x = it;
                while(st.find(x + 1) != st.end()) {
                    x += 1;
                    cnt += 1;
                }
                longestSequence = max(longestSequence, cnt);
            }
        }
        return longestSequence;
    }
};
