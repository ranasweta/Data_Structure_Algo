class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1 && trust.empty()){
            return 1;
        }
        vector<int> cnt(n+1,0);
        for(auto vec: trust){
            int u=vec[0];
            int v=vec[1];
            cnt[u]--;
            cnt[v]++;
        }
        for(int i=0;i<=n;i++){
            if(cnt[i]==n-1){
                return i;
            }
        }
        return -1;
    }
};