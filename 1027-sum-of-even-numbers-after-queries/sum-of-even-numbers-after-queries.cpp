class Solution {
public:
    vector<int>ans;
    void sum(vector<int>& nums,int idx,int val,int i){
        nums[idx]+=val;
        int temp=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]%2==0){
                temp+=nums[j];
            }
        }
        ans[i]=temp;
    }
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=queries.size();
        ans.resize(queries.size(),0);
        for(int i=0;i<n;i++){
            int val=queries[i][0];
            int idx=queries[i][1];
            sum(nums,idx,val,i);
        }
        return ans;
    }
};