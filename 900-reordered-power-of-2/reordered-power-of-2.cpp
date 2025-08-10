class Solution {
public:
    int numberFormat(int n){
        int v=0;
        while(n){
            v+=pow(10,n%10);
            n/=10;
        }
        return v;
    }
    bool reorderedPowerOf2(int n) {
        int inp=numberFormat(n);
        for(int p=0;p<=29;p++){
            if(inp==numberFormat(1<<p)){
                return true;
            }
        }
        return false;
    }
};