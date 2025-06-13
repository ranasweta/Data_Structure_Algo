class Solution {
public:
int n;
int dp[1001][1001];
int solve(int i,int p,vector<vector<int>>& pairs){
    if(i>=n) return 0;
    int take=0;
    if(p!=-1 && dp[i][p]!=-1) return dp[i][p];
    if(p==-1 || pairs[p][1]<pairs[i][0]){
        take=1+solve(i+1,i,pairs);
    }
    int skip=solve(i+1,p,pairs);
    if(p!=-1 ){
        dp[i][p]=max(skip,take);
    }
    return max(skip,take);

}
    int findLongestChain(vector<vector<int>>& pairs) {
        memset(dp,-1,sizeof(dp));
        sort(pairs.begin(),pairs.end());
        n=pairs.size();
        return solve(0,-1,pairs);
    }
};