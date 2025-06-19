class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>t(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((i==0 )||(j==0)){
                    t[i][j]=1;
                }
                else{

                t[i][j]=t[i][j-1]+t[i-1][j];
                }
            }
        }
        return t[m-1][n-1];

    }
};