https://leetcode.com/problems/validate-binary-search-tree/

class Solution {
public:
    // Recursive function to check if the BST property is maintained
    bool rec(TreeNode* root, long long minValue, long long maxValue) {
        // Check the left subtree if it exists
        if (root->left != NULL) {
            // Check if the left child's value is greater than the minimum value and less than the root's value
            if (root->val > root->left->val && root->left->val > minValue) {
                // Recursively check the left subtree
                if (!rec(root->left, minValue, root->val))
                    return false;
            } else {
                return false;  // If the condition is not met, the BST property is violated
            }
        }

        // Check the right subtree if it exists
        if (root->right != NULL) {
            // Check if the right child's value is less than the maximum value and greater than the root's value
            if (root->val < root->right->val && root->right->val < maxValue) {
                // Recursively check the right subtree
                if (!rec(root->right, root->val, maxValue))
                    return false;
            } else {
                return false;  // If the condition is not met, the BST property is violated
            }
        }

        return true;  // If all conditions are met, the BST property is maintained
    }

    // Function to check if the given binary tree is a valid BST
    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;  // An empty tree is considered a valid BST

        long long max = LONG_LONG_MAX;   // Maximum value for root's initial value
        long long min = LONG_LONG_MIN;   // Minimum value for root's initial value

        // Call the recursive function with initial root's value range
        return rec(root, min, max);
    }
};
