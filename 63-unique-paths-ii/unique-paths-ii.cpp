class Solution {
public:
int dp[101][101];
int m,n;
int solve(int i,int j,vector<vector<int>>& Grid){
    if(i>m-1||i<0||j>n-1||j<0||Grid[i][j]==1) return 0;
    if(i==m-1 && j==n-1) return 1;//1 path found
    if(dp[i][j]!=-1) return dp[i][j];
    int right=solve(i,j+1,Grid);
    int down=solve(i+1,j,Grid);
    return dp[i][j]=right+down;
}
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        m=Grid.size();
        n=Grid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(0,0,Grid);
    }
};