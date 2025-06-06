class Solution {
public:
    string robotWithString(string s) {
        int n=s.length();
        vector<char> mincharToRight(n);
        mincharToRight[n-1]=s[n-1];//iske right me kuch hai hi nhi
        for(int i=n-2 ; i>=0;i--){
            mincharToRight[i]=min(s[i],mincharToRight[i+1]);

        }
        int i=0;
        string r="";
        string t="";
        while(i<n){
            t.push_back(s[i]);
            char minchar=(i+1<n)?mincharToRight[i+1]:s[i];
            while(!t.empty() && t.back()<=minchar){
                r+=t.back();
                t.pop_back();
            }
            i++;
        }
        while(!t.empty()){
            r+=t.back();
            t.pop_back();
        }
        return r;
    }
};