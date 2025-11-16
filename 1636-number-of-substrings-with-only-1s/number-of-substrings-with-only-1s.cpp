class Solution {
public:
    int numSub(string s) {
        long long  ans=0;
        long long one=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0') {
                ans+=one*(one+1)/2;
                one=0;
                }
            else{
                one++;
            }
        }
        ans+=one*(one+1)/2;
        return ans % 1000000007;
    }
};