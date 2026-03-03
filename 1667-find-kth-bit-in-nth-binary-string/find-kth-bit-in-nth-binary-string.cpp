class Solution {
public://simple brute 
    string invert(string s){
        for(int i=0;i<s.length();i++){
            s[i]=(s[i]=='0')?'1':'0';
        }
        return s;
    }
    string reverse(string &s){
            string a=invert(s);
            s=s+'1';
            for(int i=a.size()-1;i>=0;i--){
                s+=a[i];
            }
            return s;

    }
    char findKthBit(int n, int k) {
        if(n==1 && k==1){
            return '0';
        }
        string s="0";
        for(int i=1;i<n;i++){
            s=reverse(s);
     
        }
        return s[k-1];

    }
};