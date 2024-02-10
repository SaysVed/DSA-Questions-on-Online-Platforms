https://leetcode.com/problems/missing-number/

class Solution {
public:
    // Function to find the missing number in an array of consecutive numbers
    int missingNumber(vector<int>& nums) {
        int n = nums.size();  // Number of elements in the array
        int sum = n * (n + 1) / 2;  // Sum of consecutive numbers from 0 to n
        int c = 0;

        // Calculate the sum of elements in the given array
        for (int i = 0; i < n; i++) {
            c += nums[i];
        }

        return sum - c;  // Return the missing number
    }
};
