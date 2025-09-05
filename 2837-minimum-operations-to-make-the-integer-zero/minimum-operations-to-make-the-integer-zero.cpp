class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int i=0;i<=60;i++){
            long long int target=num1-num2*1LL*i;
            if(target<=0) return -1;
            int bits=__builtin_popcountll(target);//used to find no. of set bits 
            if(bits<=i && target >=i){
                return i;
            }
        }
        return -1;
    }
};