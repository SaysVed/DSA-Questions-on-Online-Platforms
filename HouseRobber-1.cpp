https://leetcode.com/problems/house-robber/

class Solution {
public:
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

        vector<int> robT(n);  // DP array to store maximum amount that can be robbed at each house
        robT[0] = nums[0];    // Maximum amount that can be robbed from the first house
        robT[1] = max(nums[0], nums[1]);  // Maximum amount that can be robbed from the first two houses

        // Iterate over the remaining houses
        for (int i = 2; i < n; i++) {
            // Calculate the maximum amount that can be robbed at the i-th house
            robT[i] = max(robT[i - 2] + nums[i], robT[i - 1]);
        }

        return robT[n - 1];  // Return the maximum amount that can be robbed from all houses
    }
};
