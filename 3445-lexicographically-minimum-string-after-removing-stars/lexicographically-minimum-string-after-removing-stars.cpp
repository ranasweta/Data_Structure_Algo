class Solution {
public:
    string clearStars(string s) {
        unordered_set<int> r;
        unordered_map<char,vector<int>> mp;//for every character hashing
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='*')
            {
                for(char ch='a';ch<='z';ch++){
                   if(!mp[ch].empty()){

                    r.insert(mp[ch].back());
                    mp[ch].pop_back();
                    break;
                   }
                }
            }
            mp[s[i]].push_back(i);
        }
        string res="";
        for(int i=0;i<n;i++){
            if(!r.count(i) && s[i]!='*'){
                res+=s[i];
            }
        }
        return res;
    }
};