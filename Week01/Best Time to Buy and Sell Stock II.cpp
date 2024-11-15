class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int sum = 0;
        for(int i = 1; i < n; i++) {
            int profit = 0;
            if(prices[i] > prices[i-1]) {
                profit = prices[i] - prices[i-1];
            }
            sum += profit;
        }
        return sum;
    }
};
