https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

class Solution {
public:
    // Function to calculate the maximum profit from buying and selling stocks multiple times
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];    // Initialize the buying price with the first day's stock price
        int profit = 0;         // Initialize the profit for each transaction
        int totalP = 0;         // Initialize the total profit over all transactions

        for (int i = 0; i < prices.size(); i++) {
            if (buy > prices[i]) {
                buy = prices[i];  // Update the buying price if a lower price is encountered
                continue;
            }

            if (prices[i] > buy) {
                profit = prices[i] - buy;  // Calculate the profit if a higher selling price is encountered
                totalP += profit;          // Add the profit to the total profit
                buy = prices[i];           // Update the buying price for the next transaction
            }
        }

        return totalP;  // Return the total profit achievable by multiple transactions
    }
};
