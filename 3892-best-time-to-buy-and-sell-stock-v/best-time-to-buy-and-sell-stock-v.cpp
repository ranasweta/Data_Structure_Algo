class Solution {
public: 
    int n;
    vector<int> prices;
    // 3D DP table: dp[index][case][transactions]
    vector<vector<vector<long long>>> dp;

    long long solve(int i, int CASE, int k) {
        if (i == n) {
            if (CASE == 0) return 0;
            return -1e15; 
        }

        // Check if value is already computed (not -1)
        if (dp[i][CASE][k] != -1) {
            return dp[i][CASE][k];
        }

        long long take = -1e15;
        long long nottake = solve(i + 1, CASE, k);

        if (k > 0) {
            if (CASE == 1) {
                take = prices[i] + solve(i + 1, 0, k - 1);
            }
            else if (CASE == 2) {
                take = -prices[i] + solve(i + 1, 0, k - 1);
            }
            else {
                take = max(
                    -prices[i] + solve(i + 1, 1, k), 
                    prices[i] + solve(i + 1, 2, k)   
                );
            }
        }

        // Store in table
        return dp[i][CASE][k] = max(take, nottake);
    }

    long long maximumProfit(vector<int>& prices_, int k) {
        prices = prices_;
        n = prices_.size();
        
        // Initialize 3D vector with -1
        // Size: [n][3][k+1]
        dp.resize(n, vector<vector<long long>>(3, vector<long long>(k + 1, -1)));
        
        return solve(0, 0, k);
    }
};