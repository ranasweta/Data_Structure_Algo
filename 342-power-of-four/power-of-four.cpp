class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0){
            return false;
        }
        int zeros=0,ones=0;
        while(n){
            if(!(n&1)){
                zeros++;
            }
            else{
                ones++;
                if(ones>1){
                    return false;
                }
            }
            n>>=1;
        }
        return !(zeros%2) ;
    }
};