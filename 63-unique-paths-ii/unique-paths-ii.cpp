class Solution {
public://botttom up
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>t(m,vector<int>(n,0));
        //1st row
        for(int i=0;i<n;i++){
            if(i>0 && grid[0][i-1]==1){
                t[0][i]=0;
                grid[0][i]=1;//marking this side as not reachabele
            
            }
            else if(grid[0][i]==1){
                t[0][i]=0;
            }
            else{
                t[0][i]=1;
            }
        }
        //1st col
        for(int i=0;i<m;i++){
            if(i>0 && grid[i-1][0]==1){
                t[i][0]=0;
                grid[i][0]=1;//marking this side as not reachabele
            
            }
            else if(grid[i][0]==1){
                t[i][0]=0;
            }
            else{
                t[i][0]=1;
            }
        }
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(grid[i][j]==1){
                    t[i][j]=0;
                }
                else{

                t[i][j]=t[i-1][j]+t[i][j-1];
                }
            }
        }
        return t[m-1][n-1];
    }
};