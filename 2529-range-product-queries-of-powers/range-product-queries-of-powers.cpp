class Solution {
public:
    const long long MOD = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        int pow=0;
        int multiplier=1;
        while(n){
            if(n&1){
                powers.push_back(multiplier);
            }
            n>>=1;
            multiplier<<=1;

        }
        vector<int> res;
        for(auto q : queries){
            int product=1;
            for(int i=q[0];i<=q[1];i++){
                    product=(1LL*powers[i]*product)%MOD;
            }
            res.push_back(product);
        }
        return res;
    }
};