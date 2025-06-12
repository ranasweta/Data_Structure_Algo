class Solution {
public:
//bottoms up
    int rob(vector<int>& nums) {
        int n=nums.size();
        
        int pp=0;
        int p=nums[0];
        for(int i=2;i<=n;i++){
            int steal=nums[i-1]+pp;
            int skip=p;
            int temp=max(steal,skip);
            pp=p;
            p=temp;
        }
        return p;
    }
};