class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> t(n,1);
        int maxL=1;//atleast 1 toh rhega
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    t[i]=max(t[j]+1,t[i]);
                    maxL=max(maxL,t[i]);
                }
            }
        }
        return maxL;
    }
};