class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1=0;
        int sum=0;
        for(int i=1;i<=n;i++){
            if(i%m!=0){
                num1+=i;
            }
            sum+=i;
        }
        return 2*num1-sum;
    }
};