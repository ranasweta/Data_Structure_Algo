class Solution {
public:
    int n;
    vector<int> dp; // Use int to represent -1 = unvisited, 1 = true, 0 = false

    bool solve(vector<int>& nums, int idx) {
        if (idx >= n - 1) return true;
        if (dp[idx] != -1) return dp[idx];

        int furthestJump = min(idx + nums[idx], n - 1);
        for (int i = idx + 1; i <= furthestJump; ++i) {
            if (solve(nums, i)) {
               
                return dp[idx] = true;
            }
        }

   
        return dp[idx] =false;
    }

    bool canJump(vector<int>& nums) {
        n = nums.size();
        dp.resize(n, -1); // -1 = unvisited
        return solve(nums, 0);
    }
};