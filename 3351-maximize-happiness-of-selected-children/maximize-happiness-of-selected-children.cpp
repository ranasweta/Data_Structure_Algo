class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans=0;
        sort(begin(happiness),end(happiness));
        reverse(begin(happiness),end(happiness));
        int t=0;
        for(int i=0;i<k;i++){
            if(happiness[i]-t>0){
                ans+=happiness[i]-t;
            }
                t++;
        }
        
        return ans;
    }
};