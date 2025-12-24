class Solution {
public://recursion
    int n;
    int t[5001][301];
    int solve( vector<int>& coins,int amt,int i){
        if(amt==0){
            return 1;
        }
        if (i>=n || coins[i]>amt) return 0;
        if(t[amt][i]!=-1) return t[amt][i];
        int take=solve(coins,amt-coins[i],i);
        int skip=solve(coins,amt,i+1);
        return t[amt][i]=take+skip;
     }
    int change(int amount, vector<int>& coins) {
        n=coins.size();
        sort(begin(coins),end(coins));
        memset(t,-1,sizeof(t));
        return solve(coins,amount,0);
    }
};