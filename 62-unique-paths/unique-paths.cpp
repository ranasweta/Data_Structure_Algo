class Solution {
public:
int dp[101][101];
int M,N;
int solve(int i,int j){
    if(i==M-1 && j==N-1) return 1;//we have reached the D
    if(i<0||i>M||j<0||j>N) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int right=solve(i,j+1);
    int down=solve(i+1,j);
    return dp[i][j]=right+down;
}
    int uniquePaths(int m, int n) {
        M=m;
        N=n;
        memset(dp,-1,sizeof(dp));
        return solve(0,0);
    }
};