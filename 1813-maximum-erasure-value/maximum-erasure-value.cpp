class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> st;
        int sum=0;
        int res=0;
        int i=0,j=0;
        while(j<n){
            if(!st.count(nums[j])){
                sum+=nums[j];
                res=max(res,sum);
                st.insert(nums[j]);
                j++;
            }
            else{
                //we have found the duplicate
                while(i<n && st.count(nums[j])){
                    sum-=nums[i];
                    st.erase(nums[i]);
                    i++;
                }
            }
        }
        return res;
    }
};