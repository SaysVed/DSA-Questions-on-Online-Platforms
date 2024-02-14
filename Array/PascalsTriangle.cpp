https://leetcode.com/problems/pascals-triangle

class Solution {
public:
    // Function to generate Pascal's Triangle up to a given number of rows
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;  // Vector to store the generated triangle

        // Iterate through each row
        for (int i = 0; i < numRows; i++) {
            vector<int> inside;  // Vector to store the elements of the current row

            // Iterate through each element in the current row
            for (int j = 0; j < i + 1; j++) {
                if (j == 0 || j == i) {
                    inside.push_back(1);  // The first and last elements of each row are always 1
                } else {
                    // Calculate the element by adding the two elements above it in the previous row
                    int n = ans[i - 1][j] + ans[i - 1][j - 1];
                    inside.push_back(n);
                }
            }

            ans.push_back(inside);  // Add the current row to the result vector
        }

        return ans;  // Return the generated Pascal's Triangle
    }
};
