class Solution {
public://very easy will do it by 2 approaches
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size();
        vector<long long> prefixSum(n,0);
        vector<int> res(n,-1);
        prefixSum[0]=nums[0];
        for(int i=1;i<n;i++){
            prefixSum[i]=nums[i]+prefixSum[i-1];
        }
        for(int i=k;i<n-k;i++){
            long long temp=prefixSum[i+k];
            if(i-k-1>=0){
                temp-=prefixSum[i-k-1];
            }
            res[i]=temp/(2*k+1);
        }
        return res;

    }
};