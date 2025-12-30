class Solution {
public://recur+meomo    
int n;
int dp[101];
    int solve(int i,string s){
        //base
        if(i==n) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        //it will see for single character adter ith index
        int res=solve(i+1,s);
        if(i+1<n &&(s[i]=='1' || s[i]=='2' && s[i+1]<='6')){
            res+=solve(i+2,s);
        }
        return dp[i]=res;

    }
    int numDecodings(string s) {
        n=s.length();
        memset(dp,-1,sizeof(dp));
        return solve(0,s);
    }
};