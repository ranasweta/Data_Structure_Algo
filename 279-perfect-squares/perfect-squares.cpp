class Solution {
public://greedy wont give correct ans
//only using memo + recur
int dp[10001];
    int solve(int n){
        if(n==0) return 0;
        if(dp[n]!=-1) return dp[n];
        int minCount=INT_MAX;
        
        for(int i=1;i*i<=n;i++){
           //we have used this much part
            int result=1+solve(n-i*i);
            minCount=min(minCount,result);

        }
        return dp[n]=minCount;
    }
    int numSquares(int n) {
        memset(dp,-1,sizeof(dp));
        return solve(n);
    }
};