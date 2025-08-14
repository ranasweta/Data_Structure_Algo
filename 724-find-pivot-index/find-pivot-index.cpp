class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int totalSum=0;
        for(int num: nums){
            totalSum+=num;
        }
        int rightSum=0;
        int leftSum=0;
        int ans=-1;
        for(int i=0;i<nums.size();i++){
           
            rightSum=totalSum-leftSum-nums[i];
            if(leftSum==rightSum){
                ans=i;
                break;
            }
            leftSum+=nums[i];
        }
        return ans;
    }
};