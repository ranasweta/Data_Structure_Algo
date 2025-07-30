class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxElement=0;
        for(int num:nums){
            maxElement=max(maxElement,num);

        }
        int ans=1;
        int curr=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==maxElement && nums[i]==nums[i-1]){
                curr++;
                
            }
            else{
                curr=1;
            }
            ans=max(curr,ans);
        }
        return ans;
    }
};