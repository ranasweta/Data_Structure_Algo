class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> r;
        sort(begin(nums),end(nums));
        int n=nums.size();
        int cnt=0;
        int i=0;
        while(i<n){
            if(i%3==0){
                vector<int>temp;
                int p=nums[i]+k;
                while(cnt!=3){
                    if(p<nums[i]){
                        return {};
                    }
                temp.push_back(nums[i]);
                i++;
                cnt++;
                    
                }
                cnt=0;
                r.push_back(temp);
            }
        }
        return r;
    }
};