class Solution {
public:
int N,M,K;
int Mod=1e9+7;
int dp[51][51][101];
    int solve(int indx, int s,int mx){
        if(indx==N){
            if(s==K) return 1;
            return 0;
        }
        if(dp[indx][s][mx]!=-1) return dp[indx][s][mx];
        int r=0;
        for(int i=1;i<=M;i++){
            if(i>mx){
                r=(r+solve(indx+1,s+1,i))%Mod;
            }
            else
                r=(r+solve(indx+1,s,mx))%Mod;
        }
        return dp[indx][s][mx] = r % Mod;

    }
    int numOfArrays(int n, int m, int k) {
        N=n;
        K=k;
        M=m;
        memset(dp,-1,sizeof(dp));
        return solve(0,0,0);

    }
};