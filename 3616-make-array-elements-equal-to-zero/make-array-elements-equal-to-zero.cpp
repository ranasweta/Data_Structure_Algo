class Solution {
public:
    int countValidSelections(vector<int>& nums) {
        int len = nums.size(), count = 0, l = 0, r = 0;
        for (int v : nums) r += v;
        for (int i = 0; i < len; i++) {
            l += nums[i];
            r -= nums[i];
            if (nums[i] != 0) continue;
            if (l == r) count += 2;
            if (abs(l - r) == 1) count++;
        }
        return count;
    }
};
