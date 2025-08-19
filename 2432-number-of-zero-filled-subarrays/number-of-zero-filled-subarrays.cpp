class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long zeroes=0;
        long long n=nums.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                zeroes++;
                
            }
            else{
                
                ans+=(zeroes)*(zeroes+1)/2;
               
                zeroes=0;
            }
        }
        if(nums[n-1]==0){
           
            ans+=(zeroes)*(zeroes+1)/2;
            

        }
        return ans;
    }
};