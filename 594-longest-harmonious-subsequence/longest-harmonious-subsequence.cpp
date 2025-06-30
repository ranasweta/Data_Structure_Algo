class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>freq;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        int result=0;
        for(int i=0;i<nums.size();i++){
            int mn=nums[i];
            int mx=mn+1;
            if(freq.find(mn)!=freq.end() && freq.find(mx)!=freq.end()){
                result=max(result,freq[mn]+freq[mx]);
            }
        }
        return result;
    }
};