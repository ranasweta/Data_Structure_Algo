class Solution {
public:
int n;
int dp[501][501];
int solve(vector<int>& satisfaction,int i,int time){
    if(i>=n){
        return 0;
    }
    if(dp[i][time]!=-1) return dp[i][time];
    int incl=time*satisfaction[i]+solve(satisfaction,i+1,time+1);
    int excl=solve(satisfaction,i+1,time);
    return dp[i][time]=max(incl,excl);
}
    int maxSatisfaction(vector<int>& satisfaction) {
      n=satisfaction.size();
      memset(dp,-1,sizeof(dp));
      sort(begin(satisfaction),end(satisfaction));
      return solve(satisfaction,0,1);  
    }
};