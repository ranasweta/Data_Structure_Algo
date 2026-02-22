class Solution {
public:
    int binaryGap(int n) {
        int mx=0;
        int previdx=-1;
       

        int i=0;
        while(n){
            if((n&1)==1 && previdx!=-1){
                mx=max(mx,i-previdx);
                previdx=i;
            }
            if((n&1)==1 && previdx==-1){

                previdx=i;
            }
            i++;
            n>>=1;
        }
        return mx;
    }
};