class Solution {
public://step1: first write bottom up 
// then see how u have get the final answer
    string shortestCommonSupersequence(string s1, string s2) {
        int m=s1.length();
        int n=s2.length();
        vector<vector<int>>t(m+1,vector<int>(n+1));
        for(int i=0;i<m+1;i++){
            for(int j=0;j<n+1;j++){
                if(i==0 || j==0){
                    t[i][j]=i+j;
                }
                else if(s1[i-1]==s2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }
                else{
                    t[i][j]=1+min(t[i-1][j],t[i][j-1]);
                }
            }
        }
        string r="";
        int i=m,j=n;//then tracing back
        while(i>0 && j>0){
            if(s1[i-1]==s2[j-1]){
                i--;
                j--;
                r.push_back(s1[i]);
            }
            else if(t[i-1][j]<t[i][j]){
                i--;
                r.push_back(s1[i]);
            }
            else{
                j--;
                r.push_back(s2[j]);
            }
        }
        //remaining characters
        while(i>0){
            i--;
            r.push_back(s1[i]);

        }
        while(j>0){
            j--;
            r.push_back(s2[j]);

        }
        reverse(begin(r),end(r));
        return r;

    }
};