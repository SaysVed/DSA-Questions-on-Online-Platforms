https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
    // Function to calculate the maximum profit from buying and selling stocks with dynamic programming
    int maxProfit(vector<int>& prices) {
        int n = prices.size();  // Number of days
        vector<vector<int>> dp(n, vector<int>(2, 0));  // DP array to store profits

        dp[0][0] = 0;            // Initial profit with no stock held
        dp[0][1] = -prices[0];   // Initial profit with stock held on the first day

        for (int i = 1; i < n; i++) {
            // Calculate the maximum profit on the i-th day without holding a stock
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
            
            // Calculate the maximum profit on the i-th day with a stock held
            dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }

        return dp[n-1][0];  // Return the maximum profit achievable on the last day without holding a stock
    }
};

