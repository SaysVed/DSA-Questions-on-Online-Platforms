https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

class Solution {
public:
    // Function to calculate the maximum profit from buying and selling stocks with at most two transactions
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        if (n <= 1) {
            return 0;  // Not enough days to make a profit
        }

        int buy1 = prices[0];     // Buying price for the first transaction
        int profit1 = 0;          // Profit for the first transaction
        int buy2 = prices[0];     // Buying price for the second transaction
        int profit2 = 0;          // Profit for the second transaction

        for (int i = 1; i < n; i++) {
            buy1 = min(buy1, prices[i]);                  // Update buying price for the first transaction
            profit1 = max(profit1, prices[i] - buy1);      // Update profit for the first transaction
            buy2 = min(buy2, prices[i] - profit1);        // Update buying price for the second transaction
            profit2 = max(profit2, prices[i] - buy2);     // Update profit for the second transaction
        }

        return profit2;  // Return the maximum profit achievable with at most two transactions
    }
};
