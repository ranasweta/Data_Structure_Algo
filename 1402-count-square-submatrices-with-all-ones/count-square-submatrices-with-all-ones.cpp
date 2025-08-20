class Solution {
public://DP on grid
int m,n;
vector<vector<int>> dp;
    int solve(int i,int j,vector<vector<int>>& matrix){
        if(i>=m || j>=n){
            return 0;

        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(matrix[i][j]==0) return 0;
        int r=solve(i,j+1,matrix);
        int l=solve(i+1,j,matrix);
        int d=solve(i+1,j+1,matrix);
        return dp[i][j]=1+min({r,l,d});
    }
    int countSquares(vector<vector<int>>& matrix) {
         m=matrix.size();
         n=matrix[0].size();
         dp.resize(m,vector<int>(n,-1));
         int result=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1){
                    result+=solve(i,j,matrix);
                }
            }
        }
        return result;
    }
};