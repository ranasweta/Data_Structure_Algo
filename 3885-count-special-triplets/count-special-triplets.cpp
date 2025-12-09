class Solution {
public://2 pass
    int M=1e9+7;
    int specialTriplets(vector<int>& nums) {
        unordered_map<int,int> mp_r;
        unordered_map<int,int> mp_l;
        for(int & num : nums){
            mp_r[num]++;
        }
        int res=0;
        for(int &num : nums){
            mp_r[num]--;

            int r=mp_r[num*2];
            int l=mp_l[num*2];
            res=(res+(1LL*r*l))%M;
            mp_l[num]++;

        }
        return res;
        
    }
};