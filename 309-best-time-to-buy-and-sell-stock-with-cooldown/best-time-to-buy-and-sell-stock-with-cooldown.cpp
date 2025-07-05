class Solution {
public:
int n;
int dp[5001][2];
int solve(vector<int>& prices,int day,bool buy){
    if(day>=n){
        return 0;
    }
    if(dp[day][buy]!=-1){
        return dp[day][buy];
    }
    int profit=0;
    if(buy){
        int take=solve(prices,day+1,false)-prices[day];
        int not_take=solve(prices,day+1,true);
        profit=max({take,not_take,profit});
    }
    else{
        int sell=prices[day]+solve(prices,day+2,true);//cool on day+1
        int not_sell=solve(prices,day+1,false);
        profit=max({sell,not_sell,profit});
    }
    return dp[day][buy]=profit;
}
    int maxProfit(vector<int>& prices) {
      n=prices.size();
      memset(dp,-1,sizeof(dp));
      int day=0;
      bool buy=true;//initially we have to buy
      return solve(prices,day,buy);
    }
};