class Solution {
public://  n
    int dp[2501][2501];
    int n;
    
    int solve(int i,int p,vector<int>& nums){//i and prev i
        //base
        if(i>=n) return 0;
        if(p!=-1 && dp[i][p]!=-1 ) return dp[i][p];
        int take=0;
        if(p==-1 || nums[p]<nums[i]){
            take=1+solve(i+1,i,nums);
        }
            int skip=solve(i+1,p,nums);//prev i will be save
            if(p!=-1){

                dp[i][p]=max(skip,take);
            }
        return max(skip,take);

    }

    int lengthOfLIS(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));//intialise
        n=nums.size();
        return solve(0,-1,nums);

    }
};