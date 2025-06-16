class Solution {
public:
    int m,n;
    int dp[501][501];
    int solve(string s1, string s2,int i,int j){
        if(i==m || j==n){
            return m-i+n-j;//jitne bache hai usme ya toh vo del honge ya fir insert
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]){
            return dp[i][j]=solve(s1,s2,i+1,j+1);

        }
        else{
            int insertC=1+solve(s1,s2,i,j+1);
            int deleteC=1+solve(s1,s2,i+1,j);
            int replaceC=1+solve(s1,s2,i+1,j+1);
            return dp[i][j]=min({insertC,deleteC,replaceC});

        }
        return -1;

    }
    int minDistance(string s1, string s2) {
         m=s1.size();
         n=s2.size();
         memset(dp,-1,sizeof(dp));
        return solve(s1,s2,0,0);


    }
};