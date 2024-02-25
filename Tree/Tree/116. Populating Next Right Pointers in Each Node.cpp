116. Populating Next Right Pointers in Each Node

https://leetcode.com/problems/populating-next-right-pointers-in-each-node/description

class Solution {
public:
    // Function to connect each node to its next right node in a perfect binary tree
    Node* connect(Node* root) {
        if (root == NULL) {
            return root;  // Return null for an empty tree
        }

        queue<Node*> q;  // Queue to store nodes for level order traversal
        q.push(root);    // Enqueue the root node

        while (!q.empty()) {
            Node* prev = nullptr;  // Pointer to the previous node at the current level
            int levelSize = q.size();  // Get the size of the current level

            for (int i = 0; i < levelSize; i++) {
                Node* node = q.front();  // Dequeue the front node
                q.pop();

                if (prev != nullptr) {
                    prev->next = node;  // Connect the previous node to the current node
                }

                prev = node;  // Update the previous node

                // Enqueue the left and right children of the current node if they exist
                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
            }
        }

        return root;  // Return the modified root with connections between nodes
    }
};
