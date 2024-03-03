55. Jump Game

https://leetcode.com/problems/jump-game/description

class Solution {
public:
    // Function to determine if it is possible to reach the last index in an array using jumps
    bool canJump(vector<int>& nums) {
        int maxReach = 0;  // Variable to store the maximum reachable index
        int n = nums.size();  // Number of elements in the array

        for (int i = 0; i < n; i++) {
            if (i > maxReach) {
                return false;  // If the current index cannot be reached, return false
            }

            maxReach = max(maxReach, i + nums[i]);  // Update the maximum reachable index

            if (maxReach >= n - 1) {
                return true;  // If the last index can be reached, return true
            }
        }

        return false;  // If the last index cannot be reached, return false
    }
};

