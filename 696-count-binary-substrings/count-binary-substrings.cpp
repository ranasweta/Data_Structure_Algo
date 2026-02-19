class Solution {
public:
    int countBinarySubstrings(string s) {
        int cz=(s[0]=='1'? 0:1),co=(s[0]=='1'? 1:0);
        int ans=0;
        for(int i=1;i<s.size();i++){
            if(s[i-1]!=s[i]){
                    ans+=min(cz,co);
                if(s[i]=='0' ){
                    cz=1;

                }
                else{
                    co=1;
                }
            }
            else{
                if(s[i]=='0'){
                    cz++;
                }
                else{
                    co++;
                }
            }
        }
                    ans+=min(cz,co);
        return ans;
    }
};