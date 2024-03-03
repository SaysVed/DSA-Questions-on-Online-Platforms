https://leetcode.com/problems/range-sum-query-immutable/description/


class NumArray {
private:
    vector<int> prefixSum;  // Vector to store prefix sums
public:
    // Constructor to initialize the prefix sum array
    NumArray(vector<int>& nums) {
        prefixSum.resize(nums.size());
        prefixSum[0] = nums[0];

        // Calculate and store the prefix sums
        for (int i = 1; i < nums.size(); i++)
            prefixSum[i] = prefixSum[i - 1] + nums[i];
    }

    // Function to return the sum of elements within a given range [left, right]
    int sumRange(int left, int right) {
        if (left == 0) {
            return prefixSum[right];  // If left is 0, return the prefix sum at the right index
        }
        return prefixSum[right] - prefixSum[left - 1];  // Otherwise, return the difference between prefix sums
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left, right);
 */
