class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> res;
        for(int num: nums){
            if(num==2) {
                res.push_back(-1);
                continue;
            }
            for(int i=0;i<32;i++){
                //agar bit set hai piche se
                if((num & (1<<i))){
                    continue;
                }
                
                int x=(num^(1<<(i-1)));
                res.push_back(x);
                break;
            }
        }
        return res;
    }
};