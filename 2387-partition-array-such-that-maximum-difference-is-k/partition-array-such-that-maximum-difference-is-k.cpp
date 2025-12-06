class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int minValue = nums[0];
        int cnt=1;
        for (int i = 0; i < nums.size(); i++) {
            if ((nums[i] - minValue) > k) {
                minValue=nums[i];
                cnt++;
            }
            
        }
        return cnt;
    }
};