class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end()); // Sort in increasing order

        // dp[i][t] = max total satisfaction using dishes from i to n-1 with current time t
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0)); // +2 for safe access at t+1

        for (int i = n - 1; i >= 0; i--) {
            for (int t = 1; t <= n; t++) {
                // Either take the current dish or skip it
                dp[i][t] = max(
                    satisfaction[i] * t + dp[i + 1][t + 1],
                    dp[i + 1][t]
                );
            }
        }

        return dp[0][1];
    }
};
