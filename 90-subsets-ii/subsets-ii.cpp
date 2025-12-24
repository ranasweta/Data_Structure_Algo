class Solution {
public:
    vector<vector<int>> result;
    int n;

    void solve(vector<int>& nums, int start, vector<int>& temp) {
        result.push_back(temp);  // add current subset

        for (int i = start; i < n; i++) {
            // skip duplicates at the same recursion depth
            if (i > start && nums[i] == nums[i-1]) continue;

            temp.push_back(nums[i]);
            solve(nums, i+1, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());  // sort to group duplicates
        n = nums.size();
        vector<int> temp;
        solve(nums, 0, temp);
        return result;
    }
};