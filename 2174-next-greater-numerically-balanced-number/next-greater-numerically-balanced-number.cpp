class Solution {
public:
    bool balanced(int n){
        vector<int> cnt(10,0);
        while(n>0){
            cnt[n%10]++;
            n=n/10;

        }
        for(int i=0;i<=9;i++){
            if(cnt[i]!=i && cnt[i]>0) return false;
        }
        return true;

    }
    int nextBeautifulNumber(int n) {
        for(int i=n+1;i<=1224444;i++){
            if(balanced(i)){
                return i;
            }
        }
        return 1;
    }
};