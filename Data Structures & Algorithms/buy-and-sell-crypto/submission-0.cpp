class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int n = prices.size();

        for(int i = 0; i < n; i++){
            int buy = prices[i];
            int profit = 0;
            for(int j = i + 1; j < n; j++){
                profit = prices[j] - buy;
                ans = max(ans, profit);
            }
        }
        return ans;
    }
};
