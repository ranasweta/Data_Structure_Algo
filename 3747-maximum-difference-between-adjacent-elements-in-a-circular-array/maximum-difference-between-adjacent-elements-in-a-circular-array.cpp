class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int mx=0;
        int n=nums.size();
        int i=0;
        int j=i+1;
        while(i<j){
            if(abs(nums[j]-nums[i]
            ) >mx){
                mx=abs(nums[j]-nums[i]);
            }
            i++;
            j=(i+1)%n;
        }
        if(abs(nums[n-1]-nums[0])>mx){
            mx=abs(nums[n-1]-nums[0]);
        }
        return mx;
    }
};