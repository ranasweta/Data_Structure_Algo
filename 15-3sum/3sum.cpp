class Solution {
public:
int n;
        vector<vector<int>>result;

    void twoSum(vector<int>& nums,int i,int j,int target){
        while(i<j){
            if(nums[i]+nums[j]<target)i++;
            else if(nums[i]+nums[j]>target)j--;
            else{
                while(i<j && nums[i]==nums[i+1])i++;
                while(i<j && nums[j]==nums[j-1])j--;
                result.push_back({-target,nums[i],nums[j]});
                i++;
                j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        n=nums.size();
        if(n<3){
            return {};
        }
        sort(begin(nums),end(nums));
        result.clear();
        for(int i=0;i<n-2;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            
            twoSum(nums,i+1,n-1,-nums[i]);
           
        }
return result;
    }
};