class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();

        vector<int> res(n,0);
        for(int i=0;i< n;i++){
            int idx=0;
            if(nums[i]>0){
                idx=(i+nums[i])%n;
                res[i]=nums[idx];
            }
            else if(nums[i]<0){
                int k=abs(nums[i]%n);
                res[i]=nums[(i-k+n)%n];
            }
            else{
                res[i]=nums[i];
            }
        }

        return res;
    }
};