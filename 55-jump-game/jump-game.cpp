class Solution {
public:
    int n;
    vector<int> dp; // Use int to represent 0 = unvisited, 1 = true, -1 = false

    bool solve(vector<int>& nums, int idx) {
        if (idx >= n - 1) return true;
        if (dp[idx] != 0) return dp[idx] == 1;

        int furthestJump = min(idx + nums[idx], n - 1);
        for (int i = idx + 1; i <= furthestJump; ++i) {
            if (solve(nums, i)) {
                dp[idx] = 1;
                return true;
            }
        }

        dp[idx] = -1;
        return false;
    }

    bool canJump(vector<int>& nums) {
        n = nums.size();
        dp.resize(n, 0); // 0 = unvisited
        return solve(nums, 0);
    }
};