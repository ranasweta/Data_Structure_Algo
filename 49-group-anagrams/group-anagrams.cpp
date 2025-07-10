class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<strs.size();i++){
            string s=strs[i];
            sort(begin(s),end(s));
            mp[s].push_back(strs[i]);
        }
        vector<vector<string>>r;
        for(auto [key,value]:mp){
            r.push_back(value);
        }
        return r;

    }
};