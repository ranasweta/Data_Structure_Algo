class Solution {
public:
    vector<pair<int,int>> pour={{100,0},{75,25},{50,50},{25,75}};

    vector<vector<double>>dp;
    double solve(int a,int b){
        if(a<=0 && b<=0) return 0.5;
        if(a<=0) return 1;
        if(b<=0) return 0;
        if(dp[a][b]!=-1){
            return dp[a][b];
        }
        double prob=0.0;
        for(auto p: pour){
            int a_pour=p.first;
            int b_pour=p.second;
            prob+=solve(a-a_pour,b-b_pour);
        }
        return dp[a][b]=prob*0.25;
    }
    double soupServings(int n) {
        if(n>=5000){
            return 1;
        }
        dp.resize(n+1,vector<double> (n+1,-1));
        return solve(n,n);

    }
};