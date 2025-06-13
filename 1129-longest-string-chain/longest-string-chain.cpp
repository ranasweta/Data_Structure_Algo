class Solution {
public:
int dp[1001][1001];
int n;
bool isPre(string &w1,string &w2){
    int e=w1.size();
    int m=w2.size();
    if(e>m || m-e!=1) return false;
    int i=0,j=0;
    while(i<e && j<m){
        if(w1[i]==w2[j]){
            i++;
        }
        j++;
    }
    return i==e;
}
static bool myfunc(string &w1,string &w2){
    return w1.length()<w2.length();
}
int solve(int i,int p,vector<string>& words){
        if(i>=n) return 0;
        if(p!=-1 && dp[p][i]!=-1) return dp[p][i];
        long long take=0,skip=0;
        if(p==-1 || isPre(words[p],words[i])){
            take=1+solve(i+1,i,words);
        }
        skip=solve(i+1,p,words);
        if(p!=-1){
            dp[p][i]=max(skip,take);
        }
        return max(skip,take);
}
    int longestStrChain(vector<string>& words) {
        n=words.size();
        memset(dp,-1,sizeof(dp));
        sort(begin(words),end(words),myfunc);
        return solve(0,-1,words);
    }
};