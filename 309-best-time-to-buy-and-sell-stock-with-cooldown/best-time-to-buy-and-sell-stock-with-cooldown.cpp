class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==1){
            return 0;
        }
        vector<int>t(n,0);
        //t[i] max total profit till day i t[0]=0
        //       sell       buy
        t[1]=max(prices[1]-prices[0],0);
        for(int i=2;i<n;i++){
            t[i]=t[i-1];
            for(int j=0;j<=i-1;j++){
                int prev_profit=j>=2?t[j-2]:0;
                t[i]=max(t[i],prices[i]-prices[j]+prev_profit);
            }
        }
        return t[n-1];

    }
};