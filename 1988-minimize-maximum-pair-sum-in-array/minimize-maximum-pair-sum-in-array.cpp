class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int res=0;
        sort(begin(nums),end(nums));
        int i=0,j=nums.size()-1;
        int sum=0;
        while(i<j){
sum=nums[i]+nums[j];
res=max(sum,res);
i++;
j--;
        }
        return res;
    }
};