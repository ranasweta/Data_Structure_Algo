class Solution {
public:
    int solve(int n,vector<int>&dp){
        if(n<=1) return n;
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=solve(n-1,dp)+solve(n-2,dp);
    }
    int fib(int n) {
        if(n<=1)
        return n;
        int c,a=0;
        int b=1;
        for(int i=2;i<=n;i++){
            c=a+b;
            a=b;
            b=c;
        }
        return c;
    }
};