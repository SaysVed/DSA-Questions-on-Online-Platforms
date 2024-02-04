https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description


class Solution {
public:
    // Recursive function to build a balanced BST from a sorted array
    TreeNode* rec(vector<int> & nums, int start, int end){
        // Base case: If the start index is greater than the end index, return NULL
        if(start > end){
            return NULL;
        }
        
        // Calculate the middle index
        int mid = (start + end) / 2;

        // Create a new TreeNode with the value at the middle index
        TreeNode* root = new TreeNode(nums[mid]);

        // Recursively build the left subtree with elements to the left of the middle index
        root->left = rec(nums, start, mid - 1);

        // Recursively build the right subtree with elements to the right of the middle index
        root->right = rec(nums, mid + 1, end);

        // Return the root of the constructed subtree
        return root;
    }

    // Function to convert a sorted array to a balanced BST
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        // Initialize start and end indices
        int start = 0;
        int end = nums.size() - 1;

        // Call the recursive function to build the BST and return the root
        TreeNode* root = rec(nums, start, end);
        return root;
    }
};
