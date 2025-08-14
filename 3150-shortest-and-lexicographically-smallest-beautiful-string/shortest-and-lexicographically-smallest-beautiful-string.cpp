class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n=s.length();
        string ans;
        int l=0,r=0,cnt=0;
        while(r<n){
            if(s[r]=='1'){
                cnt++;
            }
            if(cnt==k){
                while(l<n && cnt ==k){
                    string sub=s.substr(l,r-l+1);
                    if(ans.empty() || sub.size()<ans.size()){
                        ans=sub;
                    }
                    else if( sub.size()==ans.size()){
                        ans=min(ans,sub);
                    }
                    if(s[l]=='1'){
                        cnt--;
                    }
                    l++;
                }
            }
            r++;
        }
        return ans;
    }
};