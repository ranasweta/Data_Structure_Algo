class Solution {
public://similar to house robber 1 bus 2 case banenge ek me esa krenge ki pehle vaale ko rkhnge toh last vala nhi rhega us chori me 
//2nd me 1st hatega and dusra rkhenge

    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        int t[n];
        t[0]=0;
        t[1]=nums[0];//pehla include last exclude
        for(int i=2;i<n;i++){
            int steal =nums[i-1]+t[i-2];
            int skip=t[i-1];
            t[i]=max(steal,skip);
        }
        int r=t[n-1];
        t[1]=nums[1];
        for(int i=2;i<n;i++){
            int steal =nums[i]+t[i-2];
            int skip=t[i-1];
            t[i]=max(steal,skip);
        }
        return max(r,t[n-1]);
    }
};