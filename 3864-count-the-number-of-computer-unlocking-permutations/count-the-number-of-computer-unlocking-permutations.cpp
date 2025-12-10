class Solution {
public:
    int M=1e9+7;
    int countPermutations(vector<int>& c) {
        int res=1;
        for(int i=1;i<c.size();i++){
            if(c[i]<=c[0]) return 0;
            res=(1LL*res*i)%M;
        }
        return res;
    }
};