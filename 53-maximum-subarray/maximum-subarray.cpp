class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxS=nums[0];
        int curr=0;
        for(int &n:nums){
            if(curr<0){
                curr=0;
            }
            curr+=n;
            maxS=max(maxS,curr);
        }
        return maxS;
    }
};