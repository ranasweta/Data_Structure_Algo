class Solution {
public:
    //binary search
    bool isvalid(vector<int>& nums, int p,int n){
        int cnt=0;
        int i=0;
        while(i<nums.size()-1){
            if(nums[i+1]-nums[i]<=n){
                cnt++;
                i+=2;
            }
            else{
                i+=1;
            }

        }
        return cnt>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int r=nums[n-1]-nums[0];
        int l=0;
        int re=INT_MAX;
        while(l<=r){
            int mid =l+(r-l)/2;
            if(isvalid(nums,p,mid)){
            re=mid;
            r=mid-1;


            }
            else{
                l=mid+1;
            }        }
            return re;
    }
};