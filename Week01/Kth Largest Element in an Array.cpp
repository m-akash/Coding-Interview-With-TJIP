class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> MinHeap;
        for(auto it : nums) {
            MinHeap.push(it);
            if(MinHeap.size() > k) {
                MinHeap.pop();
            }
        }
        return MinHeap.top();
    }
};
