class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        int cnt =0;
        int i=0;
        while(i<n){
            int st=nums[i];
            cnt++;
            while(i<n && nums[i]-st<=k){
                i++;
            }
            
            
        }
        return cnt;
    }
};