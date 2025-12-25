class Solution {
public://rescursion
    int n;
    unordered_set <string> dict;
    int t[301];
    bool solve(int idx,string s){
        if(idx==n){//it has been finished already true is returnred
            return true;
        }
        if(t[idx]!=-1) return t[idx];
        if(dict.find(s)!=dict.end()){
            return t[idx]=true;
        }
       for(int l=1;l<=n;l++){
        string temp=s.substr(idx,l);
        if(dict.find(temp)!=dict.end() && solve(idx+l,s)){
            return t[idx]=true;
        }

       }
       return t[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n=s.length();
        for(string c:wordDict){
            dict.insert(c);
        }
        memset(t,-1,sizeof(t));
        return solve(0,s);

    }
};