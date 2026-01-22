class Solution {
public://very brute force
    int minidx(vector<int>& nums){
        int mn=INT_MAX;
        int idx=0;
        for(int i=0;i<nums.size()-1;i++){
            if (mn>nums[i]+nums[i+1]){
               idx=i;
                mn=nums[i]+nums[i+1];
            }

        }
        return idx;
    }
    int minimumPairRemoval(vector<int>& nums) {
      int ans=0;
      while(!is_sorted(begin(nums),end(nums))){
        int idx=minidx(nums);

        nums[idx]=nums[idx]+nums[idx+1];
        nums.erase(begin(nums)+idx+1);
        ans++;
      }
      return ans;

    }
};