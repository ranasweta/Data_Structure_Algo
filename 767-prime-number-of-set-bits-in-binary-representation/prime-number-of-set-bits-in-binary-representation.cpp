class Solution {
public:
    int findbit(int num){
        int n=0;
        while(num){
            n+=(num&1);
            num>>=1;
        }
        return n;
    }
    int countPrimeSetBits(int left, int right) {
        vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        int ans=0;
        for (int i = left; i <= right; i++) {
                int n=findbit(i);
                for(int j=0;j<prime.size();j++){
                    if(n==prime[j]){
                        ans++;
                    } 
                }

        }
        return ans;
    }
};