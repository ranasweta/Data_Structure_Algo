class Solution {
public://brute froce
    int balanced(vector<int> &a){
        int c=0;
        for(int i=0;i<26;i++){
            if(a[i]==0)continue;
            if(c==0) c=a[i];
            if(a[i]!=c) return false;
        }
        return true;
    }
    int longestBalanced(string s) {
        int n=s.size();
                    int maxi=0;
        for(int i=0;i<n;i++){
            vector<int> a(26,0);
            for(int j=i;j<n;j++){
                a[s[j]-'a']++;
                if(balanced(a)){
                    maxi=max(maxi,j-i+1);
                }
            }
        }
        return maxi;
    }
};