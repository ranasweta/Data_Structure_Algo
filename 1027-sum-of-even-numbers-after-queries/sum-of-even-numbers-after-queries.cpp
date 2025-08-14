class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums,
                                    vector<vector<int>>& queries) {
        int evenSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (!(nums[i] % 2)) {
                evenSum += nums[i];
            }
        }
        
        vector<int> ans;
        for (auto q : queries) {
            int val = q[0];
            int idx = q[1];
            if (!(nums[idx] % 2)) {
                evenSum -= nums[idx];
            }
            nums[idx] += val;
            if (!(nums[idx] % 2)) {
                evenSum += nums[idx];
            }
            ans.push_back(evenSum);
        }
        return ans;
    }
};