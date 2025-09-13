class Solution {
public://classic binary search 
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=n-1;
        if(nums[r]>nums[l]){
            return nums[l];
        }
        while(l<r){
            int mid=l+(r-l)/2;
            if(nums[mid]>nums[r]){
                l=mid+1;
            }
            else {
                r=mid;
            }
        }
        return nums[r];
    }
};