// Pushed: 2026-08-24 21:44:39 UTC
// Difficulty: Easy
// Runtime: 0 ms
// Memory: 8.6 MB

class Solution {
public:

    int climbStairs(int n) {

        vector<int> memo(n + 1, 0);

        return rec(n, memo);
    }

    int rec(int n, vector<int>& memo) {

        if (n <= 1)
            return 1;

        if (memo[n] > 0)
            return memo[n];

        int op1 = rec(n - 1, memo);
        int op2 = rec(n - 2, memo);

        memo[n] = op1 + op2;

        return memo[n];
    }
};