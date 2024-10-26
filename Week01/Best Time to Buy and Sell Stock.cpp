class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0; int minSoFar = prices[0];
        for(int i = 1; i < n; i++){
            int profit = prices[i] - minSoFar;
            maxProfit = max(maxProfit, profit);
            minSoFar = min(minSoFar, prices[i]);
        }
        return maxProfit;
    }
};
