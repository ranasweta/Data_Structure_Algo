class Solution {
public://dp 
    vector<int> p;
    int n;
    vector<vector<vector<int>>>dp;
    int solve(int idx,int buy,int txn){
        if(txn==0 || idx==n) return 0;
        if(dp[idx][buy][txn]!=-1) return dp[idx][buy][txn];
        
        if(buy){
            return dp[idx][buy][txn]=max(
                solve(idx+1,0,txn)-p[idx],
                solve(idx+1,1,txn)
            );
        }
        
            return dp[idx][buy][txn]=max(
                solve(idx+1,1,txn-1)+p[idx],
                solve(idx+1,0,txn)
            );
    }
    int maxProfit(vector<int>& prices) {
        p=prices;
        n=prices.size();
        dp.resize(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,1,2);
    }
};