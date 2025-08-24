class Solution {
public:
    int longestSubarray(vector<int>& nums) {
       int zero=0,ans=0,strt=0;
       for(int i=0;i<nums.size();i++){
        zero+=(nums[i]==0);
        while(zero > 1){
            zero-=(nums[strt]==0);
            strt++;
        }
        ans=max(ans,i-strt);
       }
       return ans;
    }
};