class Solution {
public://writing revursive
    int solve(vector<int>& nums, int l,int r,int t){
        if(l>r) return -1;
        int mid=l+(r-l)/2;
        if(nums[mid]==t){
            return mid;
        }
        else if(nums[mid]<t){
            return solve(nums,mid+1,r,t);
        }
        else{
            return solve(nums,l,mid-1,t);
        }
    }
    int search(vector<int>& nums, int t) {
        int n=nums.size();
        return solve(nums,0,n-1,t);
    }
};