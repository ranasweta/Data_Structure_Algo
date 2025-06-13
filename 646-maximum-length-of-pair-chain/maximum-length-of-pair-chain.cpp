class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<int> t(n,1);
        int maxL=1;//atleast 1 toh rhega
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(pairs[j][1]<pairs[i][0]){
                    t[i]=max(t[j]+1,t[i]);
                    maxL=max(maxL,t[i]);
                }
            }
        }
        return maxL;
    }
};