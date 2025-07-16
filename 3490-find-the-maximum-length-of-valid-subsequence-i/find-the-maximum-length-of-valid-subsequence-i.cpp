class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even=0;
        int odd=0;
        int even_odd=1;
        int prev=nums[0]%2;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                even++;
            }
            else{
                odd++;
            }
            if(i>0 && nums[i]%2!=prev){
                even_odd++;
                prev=!prev;
            }

        }
        int ans=max({even,odd,even_odd});
        return ans;

    }
};