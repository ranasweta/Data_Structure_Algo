class Solution {
public:
    vector<int> p;
    int n;
    vector<vector<vector<int>>> dp;
    int solve(int idx,int buy,int k){
        if(k==0 || idx==n) return 0;
        if(dp[idx][buy][k]!=-1) return dp[idx][buy][k];
        if( buy){
            return dp[idx][buy][k]=max(
                solve(idx+1,0,k)-p[idx],
                solve(idx+1,1,k)
            );
        }
        return dp[idx][buy][k]=max(
            solve(idx+1,1,k-1)+p[idx],
            solve(idx+1,0,k)
        );
    }
    int maxProfit(int k, vector<int>& prices) {
        n=prices.size();
        p=prices;
        dp.resize(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return solve(0,1,k);
    }
};