https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    // Recursive function to generate valid parentheses combinations
    void rec(vector<string> &ans, int open, int close, string s, int n) {
        // Base case: If the number of open and close parentheses are both equal to n
        if (open == n && close == open) {
            ans.push_back(s);  // Add the generated combination to the result vector
        }

        // Recursive case: Add an open parenthesis if the count of open parentheses is less than n
        if (open < n) {
            s += '(';
            rec(ans, open + 1, close, s, n);
            s.pop_back();  // Backtrack by removing the last character
        }

        // Recursive case: Add a close parenthesis if the count of close parentheses is less than the count of open parentheses
        if (close < open) {
            s += ')';
            rec(ans, open, close + 1, s, n);
            s.pop_back();  // Backtrack by removing the last character
        }
    }

    // Function to generate all valid combinations of parentheses
    vector<string> generateParenthesis(int n) {
        vector<string> ans;  // Result vector to store valid combinations
        string s;            // Current combination being formed
        int open = 0;        // Count of open parentheses
        int close = 0;       // Count of close parentheses
        rec(ans, open, close, s, n);  // Call the recursive function
        return ans;  // Return the vector of valid combinations
    }
};
