// https://leetcode.com/problems/maximum-length-of-repeated-subarray/description/

class Solution {
public:
    // Function to find the length of the longest common subarray between two arrays
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(nums1.size() + 1, vector<int>(nums2.size() + 1));  // 2D DP array to store lengths of common subarrays
        int maxN = 0;  // Variable to store the maximum length of common subarray

        // Iterate through each element of nums1 and nums2
        for (int i = 1; i <= nums1.size(); i++) {
            for (int j = 1; j <= nums2.size(); j++) {
                // If the elements are equal, update the length of common subarray and update maxN
                if (nums1[i - 1] == nums2[j - 1]) {
                    ans[i][j] = ans[i - 1][j - 1] + 1;
                    maxN = max(ans[i][j], maxN);
                }
            }
        }

        return maxN;  // Return the length of the longest common subarray
    }
};
