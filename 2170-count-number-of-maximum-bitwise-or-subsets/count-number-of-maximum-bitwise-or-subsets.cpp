class Solution {
public:
int n;
int solve(vector<int>& nums,int idx,int currOr,int maxOr){
//base
if(idx>=n){
    if(currOr==maxOr){
        return 1;
    }
    return 0;
}
//taken
int taken =solve(nums,idx+1,currOr|nums[idx],maxOr);
//nottaken
int nottaken =solve(nums,idx+1,currOr,maxOr);
return nottaken+taken;
}
    int countMaxOrSubsets(vector<int>& nums) {
        n=nums.size();
        int maxOr=0;
        for(int num:nums){
            maxOr=maxOr|num;
        }
        int currOr=0;
        return solve(nums,0,currOr,maxOr);

    }
};