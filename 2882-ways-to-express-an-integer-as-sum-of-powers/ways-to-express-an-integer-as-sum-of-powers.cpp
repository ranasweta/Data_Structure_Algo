class Solution {
public://classic dp prob
#define ll long long
#define MOD 1000000007

    vector<vector<ll>> dp;
    int x,n;
    long long solve(int i,ll curr){
        if(curr==n){
            return 1;
        }
        else if(curr>n || i>n) return 0;
        if(dp[i][curr]!=-1) return dp[i][curr];
        ll take= solve(i+1,curr+pow(i,x));
        ll skip=solve(i+1,curr);
        return dp[i][curr]=(take+skip)%MOD;
    }
    int numberOfWays(int ni, int xi) {
        n=ni;
        x=xi;
        dp.resize(301,vector<ll>(n+1,-1));
        return solve(1,0);

    }
};