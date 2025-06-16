class Solution {
public:
    
    int dp[501][501];
    int solve(string s1, string s2,int m,int n){
        if(m==0 || n==0){
            return m+n;//jitne bache hai usme ya toh vo del honge ya fir insert
        }
        if(dp[m][n]!=-1) return dp[m][n];
        if(s1[m-1]==s2[n-1]){
            return dp[m][n]=solve(s1,s2,m-1,n-1);

        }
        else{
            int insertC=1+solve(s1,s2,m,n-1);
            int deleteC=1+solve(s1,s2,m-1,n);
            int replaceC=1+solve(s1,s2,m-1,n-1);
            return dp[m][n]=min({insertC,deleteC,replaceC});

        }
        return -1;

    }
    int minDistance(string s1, string s2) {
         int m=s1.size();
         int n=s2.size();
         memset(dp,-1,sizeof(dp));
        return solve(s1,s2,m,n);


    }
};