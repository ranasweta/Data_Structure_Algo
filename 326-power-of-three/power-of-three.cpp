class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<1) return false;
        for(int i=0;i<=19;i++){
            if(n==pow(3,i)) return true;
        }
        return false;

    }
};