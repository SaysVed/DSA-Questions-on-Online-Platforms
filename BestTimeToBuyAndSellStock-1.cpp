https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

class Solution {
public:
    // Function to calculate the maximum profit from buying and selling stocks
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];    // Initialize the buying price with the first day's stock price
        int profit = 0;         // Initialize the maximum profit to zero

        for (int i = 0; i < prices.size(); i++) {
            buy = min(buy, prices[i]);                  // Update the buying price if a lower price is encountered
            profit = max(profit, prices[i] - buy);      // Update the maximum profit if a higher selling price is encountered
        }

        return profit;  // Return the maximum profit achievable
    }
};

