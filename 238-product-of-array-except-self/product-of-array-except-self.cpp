class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroes = 0;
        for (int num : nums) {
            if (num == 0) {
                zeroes++;
            }
        }
        int n = nums.size();
        int mul = 1;
        int idx;
        if (zeroes == 1) {
            for (int i = 0; i < n; i++) {
                if (nums[i] == 0) {
                    idx = i;
                    continue;
                }
                mul *= nums[i];
                nums[i] = 0;
            }
            nums[idx] = mul;

        } else if (zeroes >= 2) {
            for (int i = 0; i < n; i++) {
                nums[i] = 0;
            }
        } else {
            
            for(int i=0;i<n;i++){
                mul*=nums[i];
            }
            cout<<mul;
            for(int i=0;i<n;i++){
                // cout<<nums[i]<<endl;
                nums[i]=mul/nums[i];
                // cout<<nums[i]<<endl;
            }

        }
        return nums;
    }
};