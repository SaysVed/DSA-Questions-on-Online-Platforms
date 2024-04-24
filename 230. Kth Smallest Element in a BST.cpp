https://leetcode.com/problems/kth-smallest-element-in-a-bst/description

class Solution {
public:
    // Recursive function to find the kth smallest element in a Binary Search Tree (BST)
    void rec(TreeNode* node, int &k, int &ans) {
        if (node->left != NULL) {
            rec(node->left, k, ans);  // Traverse the left subtree
        }

        k--;  // Decrement the remaining count of elements to be visited

        if (k == 0) {
            ans = node->val;  // If k becomes zero, update the answer with the current node's value
            return;
        }

        if (node->right != NULL) {
            rec(node->right, k, ans);  // Traverse the right subtree
        }
    }

    // Function to find the kth smallest element in a BST
    int kthSmallest(TreeNode* root, int k) {
        int ans;  // Variable to store the kth smallest element
        TreeNode* node = root;  // Start the traversal from the root
        rec(node, k, ans);  // Call the recursive function to find the kth smallest element
        return ans;  // Return the kth smallest element
    }
};
