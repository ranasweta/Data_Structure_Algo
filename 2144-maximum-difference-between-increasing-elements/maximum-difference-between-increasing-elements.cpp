class Solution {
public://brute force
    int maximumDifference(vector<int>& nums) {
        int mx=-1;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
            if(nums[j]<nums[i]){
                mx=max(mx,nums[i]-nums[j]);
            }
            }
        }
        return mx;
    }
};