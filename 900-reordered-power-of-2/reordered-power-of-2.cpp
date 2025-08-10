class Solution {
public:
    vector<int> getVectorCountFormat(int n){
        vector<int> v(10,0);
        while(n){
            v[n%10]++;
            n/=10;
        }
        return v;
    }
    bool reorderedPowerOf2(int n) {
        vector<int> inp=getVectorCountFormat(n);
        for(int p=0;p<=29;p++){
            if(inp==getVectorCountFormat(1<<p)){
                return true;
            }
        }
        return false;
    }
};