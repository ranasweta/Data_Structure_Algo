class Solution {
public://smart apporach
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxReachable=0;
        for(int i=0;i<n;i++){
            if(i>maxReachable) return false;
            maxReachable=max(maxReachable,nums[i]+i);        }
            return true;
    }
};