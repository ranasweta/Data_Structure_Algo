class Solution {
public:
    string largestGoodInteger(string s) {
        string ans="";
        int n=s.length();
        for(int i=0;i<n-2;i++){
            if(s[i]==s[i+1] && s[i+1]==s[i+2]){
                string temp=s.substr(i,3);
                if(ans=="" || ans<temp){
                    ans=temp;
                }
            }
        }
        return ans;
    }
};