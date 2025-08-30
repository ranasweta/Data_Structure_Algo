class Solution {
public:
    int m,n;
    vector<vector<int>>dp;
    bool solve(string s,string t,int i,int j){
        if(i==m) return true;
        if(j==n) return false;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]= solve(s,t,i+1,j+1);
        }
        else{
            return dp[i][j]= solve(s,t,i,j+1);

        }
        

    }
    bool isSubsequence(string s, string t) {
        m=s.length();
        n=t.length();
        dp.resize(m+1,vector<int>(n+1,-1));
        return solve(s,t,0,0);
    }
};