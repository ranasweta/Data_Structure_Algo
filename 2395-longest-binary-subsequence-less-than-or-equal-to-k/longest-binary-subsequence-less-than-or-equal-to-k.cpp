class Solution {
public://greedy
//0 lene se koi farak nhi padta toh jitnemile lete chalo and power bhi badhate chalo
    int longestSubsequence(string s, int k) {
        int n=s.length();
        int pow=1;//2^0
        int len=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                len++;
            }
            else if(pow<=k){
                k=k-pow;
                len++;
            }
            if(pow<=k){
                pow*=2;
            }

        }
        return len;
    }
};