class Solution {
public://bottom up
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        /*
        t[i] mean i can reach at index i
        */
        vector<bool> t(n,false);
        t[0]=true;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(t[j]==true && (j+nums[j]>=i)){
                    t[i]=true;
                    break;
                }
            }
        }
        return t[n-1];
    }
};