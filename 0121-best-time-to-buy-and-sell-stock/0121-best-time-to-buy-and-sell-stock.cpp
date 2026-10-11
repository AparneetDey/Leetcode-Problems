class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0, minCost = prices[0];

        for(int i=0; i<n; i++) {
            int sell = prices[i];
            profit = max(profit, sell - minCost);
            minCost = min(minCost, sell);
        }

        return profit;
    }
};