class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int p = 0;
        int mx=0;
        vector<vector<bool>> t(n, vector<bool>(n, false));
        for (int l = 1; l <= n; l++) { // this is the basic condition we have to
                                       // check for every length for each i
            for (int i = 0; i+l-1 < n; i++) {
                int j=i+l-1;
                if(i==j){
                    t[i][j]=true;
                }
                else if(i+1==j){
                    t[i][j]=s[i]==s[j];
                }
                else{
                    t[i][j]=(s[i]==s[j] && t[i+1][j-1]);
                }
                if(t[i][j]==true){
                    if(j-i+1>mx){
                        mx=j-i+1;
                        p=i;
                    }
                }
            }
        }
        return s.substr(p,mx);
    }
};