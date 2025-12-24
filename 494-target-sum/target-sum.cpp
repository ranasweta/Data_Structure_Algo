class Solution {
public:
    int t,n;
    int res;
    void solve(vector<int>& nums,int i,int sum){
        if(i>=n && sum!=t) return ;
        if(i>=n && sum==t){ res++;
        return ;}
        solve(nums,i+1,sum-nums[i]);
        solve(nums,i+1,sum+nums[i]);

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n=nums.size();
        res=0;
        t=target;
        solve(nums,0,0);
        return res;

    }
};