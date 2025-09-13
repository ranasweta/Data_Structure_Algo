class Solution {
public:
int n;
    int findl(vector<int>& nums, int target){
        int left_most=-1;
        int l=0,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                left_most=mid;
                r=mid-1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;

            }
        }
        return left_most;
    }
    int findr(vector<int>& nums, int target){
        int right_most=-1;
        int l=0,r=n-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                right_most=mid;
                l=mid+1;
            }
            else if(nums[mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;

            }
        }
        return right_most;

    }
    vector<int> searchRange(vector<int>& nums, int target) {
        n=nums.size();
        int right_most=findr(nums,target);
        int left_most=findl(nums,target);
        return {left_most,right_most};
    }
};