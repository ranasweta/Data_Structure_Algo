class Solution {
public://recur +  memo
    int dp[201][201];
    int m,n;
    int solve(int i,int j,vector<vector<int>>& dungeon){
        //base case
        if(i>=m || j>=n){
            return INT_MAX;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        //corners
        if(i==m-1 && j==n-1){
            if(dungeon[i][j]<=0){
                return abs(dungeon[i][j])+1;
            }
            return 1;//bus last vala jo tha vo min 1 hona chaiye
        }
        int right=solve(i,j+1,dungeon);
        int down=solve(i+1,j,dungeon);
        int r=min(right,down)-dungeon[i][j];
        return dp[i][j]=(r<=0)?1:r;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        memset(dp,-1,sizeof(dp));
        m=dungeon.size();
        n=dungeon[0].size();
        return solve(0,0,dungeon);
    }
};