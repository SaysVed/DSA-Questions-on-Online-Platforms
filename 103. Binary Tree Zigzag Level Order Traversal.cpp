103. Binary Tree Zigzag Level Order Traversal
https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description

class Solution {
public:
    // Function to perform zigzag level order traversal of a binary tree
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};  // Return an empty vector for an empty tree
        }

        queue<TreeNode*> q;      // Queue to store nodes for level order traversal
        vector<vector<int>> ans;  // Vector to store the result of zigzag level order traversal
        bool ltr = true;          // Variable to indicate the direction of traversal (left to right or right to left)

        q.push(root);  // Enqueue the root node to start the traversal

        while (!q.empty()) {
            vector<int> temp;  // Vector to store elements at the current level
            int levelSize = q.size();  // Get the size of the current level

            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front();  // Dequeue the front node
                q.pop();

                temp.push_back(node->val);  // Add the value to the current level vector

                // Enqueue the left and right children of the current node if they exist
                if (node->left != nullptr) q.push(node->left);
                if (node->right != nullptr) q.push(node->right);
            }

            if (!ltr) {
                reverse(temp.begin(), temp.end());  // Reverse the vector if the traversal direction is from right to left
            }

            ans.push_back(temp);  // Add the current level vector to the result vector
            ltr = !ltr;  // Toggle the traversal direction for the next level
        }

        return ans;  // Return the zigzag level order traversal result
    }
};
