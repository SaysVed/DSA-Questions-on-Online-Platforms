https://leetcode.com/problems/house-robber/


class Solution {
public:
    // Recursive function with memoization to calculate the maximum amount that can be robbed from houses
    int rec(vector<int> &dp, int house, int &n, vector<int>& nums) {
        if (house >= n) {
            return 0;  // Base case: No more houses to rob
        }
        if (dp[house] != -1) {
            return dp[house];  // Return the memoized value if available
        }
        // Calculate the maximum amount that can be robbed from the current house and onward
        return dp[house] = max(rec(dp, house + 1, n, nums) + 0, rec(dp, house + 2, n, nums) + nums[house]);
    }

    // Function to calculate the maximum amount that can be robbed from houses
    int rob(vector<int>& nums) {
        int n = nums.size();

        // Base cases for one or two houses
        if (n == 1) {
            return nums[0];
        }
        if (n == 2) {
            return max(nums[0], nums[1]);
        }

        vector<int> dp(n, -1);  // DP array to store maximum amount that can be robbed at each house
        rec(dp, 0, n, nums);    // Call the recursive function with memoization

        return dp[0];  // Return the maximum amount that can be robbed from the first house
    }
};
