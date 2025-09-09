class Solution {
public:
    int M=1e9+7;
    vector<int> dp;
    int solve(int day,int delay,int forget){
        if(day==1){
            return 1;
        }
        if(dp[day]!=-1) return dp[day];
        int result=0;
        for(int prev=day-forget+1;prev<=day-delay;prev++){
            if(prev>0){
                result=(result+solve(prev,delay,forget))%M;
            }
        }
        return dp[day]=result;
    }
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int total =0;
        dp.resize(n+1,-1);
        for (int day=n-forget+1;day<=n;day++){
            if(day>0){
                total=(total + solve(day,delay,forget))%M;
            }
        }
        return total;
    }
};