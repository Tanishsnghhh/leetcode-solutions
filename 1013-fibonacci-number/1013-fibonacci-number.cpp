class Solution {
public:
    int memorization(int n, vector<int>& dp) {
        if (n <= 1)
            return n;

        if (dp[n] != 0) {
            return dp[n];
        }

        int left = memorization(n - 1, dp);
        int right = memorization(n - 2, dp);
        return dp[n] = left + right;
    }

    int fib(int n) {
        vector<int> dp(n + 1, 0);
        int ans = memorization(n, dp);
        return ans;
    }
};