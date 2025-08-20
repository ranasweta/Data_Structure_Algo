class Solution {
public://bottom up
    int countSquares(vector<vector<int>>& matrix) {
        //t[i][j]= ending at i, j for the square right corner bottom
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> t(m,vector<int>(n,0));
       int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0){
                    t[i][j]=matrix[i][j];
                }
                else if(matrix[i][j]==1){
                    t[i][j]=1+min({t[i][j-1],t[i-1][j],t[i-1][j-1]});
                }
                res+=t[i][j];
            }
        }
        return res;
    }
};