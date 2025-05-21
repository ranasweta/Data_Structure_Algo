class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> a(2);
        int b;
        for (int i=0;i<nums.size();i++){
            b=target-nums[i];
            for (int j=i+1;j<nums.size();j++){
                if (nums[j]==b){
                    a[1]=j;
                    a[0]=i;
                    return a;
                }
            }
        }
        
return {};
    }
};