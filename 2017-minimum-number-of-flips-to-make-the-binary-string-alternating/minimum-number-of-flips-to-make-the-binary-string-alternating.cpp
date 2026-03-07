class Solution {
public://brute force
    int minFlips(string s) {
        int n=s.length();
        s=s+s;
        string s1,s2;
        for(int i=0;i<s.length();i++){
            s1+=(i%2==1)?'1':'0';
            s2+=(i%2==0)?'1':'0';

        }
        int flip1=0;
        int flip2=0;
        int res=INT_MAX;
        int i=0,j=0;//for sliding window
        while(j<2*n){
            if(s[j]!=s1[j]){
                flip1++;
            }
            if(s[j]!=s2[j]){
                flip2++;
            }
            if(j-i+1>n){
                if(s[i]!=s1[i]){
                    flip1--;
                }
                if(s[i]!=s2[i]){
                    flip2--;
                }
                i++;
            }
            if(j-i+1==n){
                res=min({res,flip1,flip2});
            }
            j++;
        }
        return res;
    }
};