class Solution {
public:
int n;

int solve(vector<int>& nums,int idx,int currOr,int maxOr,vector<vector<int>> &t){
//base
if(idx>=n){
    if(currOr==maxOr){
        return 1;
    }
    return 0;
}
if(t[idx][currOr]!=-1){
    return t[idx][currOr];
}
//taken
int taken =solve(nums,idx+1,currOr|nums[idx],maxOr,t);
//nottaken
int nottaken =solve(nums,idx+1,currOr,maxOr,t);
return t[idx][currOr]=nottaken+taken;
}
    int countMaxOrSubsets(vector<int>& nums) {
        n=nums.size();
        int maxOr=0;
        for(int num:nums){
            maxOr=maxOr|num;
        }
        int currOr=0;
        vector<vector<int>>t(n+1,vector<int>(maxOr+1,-1));
        return solve(nums,0,currOr,maxOr,t);

    }
};