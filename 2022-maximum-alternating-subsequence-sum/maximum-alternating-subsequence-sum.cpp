class Solution {
public:
typedef long long ll;
    long long maxAlternatingSum(vector<int>& nums) {
        ll n=nums.size();
        vector<vector<ll>>t(n+1,vector<ll>(2,0));//2d hai
        for(int i=1;i<=n;i++){
            //even legnth take                 skip
            t[i][0]=max(t[i-1][1]-nums[i-1],t[i-1][0]);
            //oddleghtn   take                  skip
            t[i][1]=max(t[i-1][0]+nums[i-1],t[i-1][1]);

        }
        return max(t[n][0],t[n][1]);
    }
};