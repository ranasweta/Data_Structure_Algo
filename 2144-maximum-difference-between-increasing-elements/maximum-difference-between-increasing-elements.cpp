class Solution {
public://optimal just keep track of the minimum element and subtract it from its bigger one  
    int maximumDifference(vector<int>& nums) {
        int r=-1;
        int minele=nums[0];
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]<minele){
                minele=nums[i];

            }
            else if(nums[i]>minele){
                r=max(r,nums[i]-minele);
            }
        }
    return r;
    }
};