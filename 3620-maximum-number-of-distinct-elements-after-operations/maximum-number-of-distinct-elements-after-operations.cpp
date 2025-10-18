class Solution {
public:
//brute froce
    int maxDistinctElements(vector<int>& nums, int k) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        int cnt=0;
        int prev=INT_MIN;
        for(int i=0;i<n;i++){
            int minVal=nums[i]-k;
            if(prev<minVal){
                //nums[i]=nums[i]-k;
                prev=minVal;
                cnt++;
            }
            else if(prev<nums[i]+k){
                //nums[i]=prev+1
                prev++;
                cnt++;
            }
        }
        return cnt;
    }
};