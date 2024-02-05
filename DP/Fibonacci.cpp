https://leetcode.com/problems/fibonacci-number/

class Solution {
public:
    // Recursive function to calculate Fibonacci numbers with memoization
    // int rec(vector<int> &tab, int n){
    //     if(n <= 1){
    //         return n;
    //     }
    //     if(tab[n] != -1){
    //         return tab[n];
    //     }
    //     tab[n] = rec(tab, n-1) + rec(tab, n-2);
    //     return tab[n];
    // }

    // Function to calculate the nth Fibonacci number using iterative dynamic programming
    int fib(int n) {
        if (n <= 1) {
            return n;
        }

        // Uncomment the following lines to use recursive approach with memoization
        // vector<int> dp(n+1, -1);
        // return rec(dp, n);

        int prepre = 0, pre = 1, curr = 0;  // Initialize variables for iterative approach
        for (int i = 2; i <= n; i++) {
            curr = prepre + pre;  // Calculate the current Fibonacci number
            prepre = pre;         // Update the values for the next iteration
            pre = curr;
        }
        return curr;  // Return the nth Fibonacci number
    }
};
