class Solution {
public:
        int t[46];

    int climbStair(int n) {
        if(n<0){
            return 0;
        }
        if(t[n]!=-1){
            return t[n];

        }
        if(n==0){
            return 1;
        }
        return t[n]=climbStair(n-1)+climbStair(n-2);
    }
    int climbStairs(int n){
        memset(t,-1,sizeof(t));
        return climbStair(n);
    }
};