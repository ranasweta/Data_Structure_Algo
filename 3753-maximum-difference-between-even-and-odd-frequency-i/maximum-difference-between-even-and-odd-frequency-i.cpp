class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            // cout<<mp[s[i]]<<endl;
        }
        int mx=0;
        int mn=100;
        for(auto &i:mp){
           
            if(i.second>mx && i.second%2==1){
                mx=i.second;
            } 
            else if(i.second<mn && i.second%2==0){
                mn=i.second;
            }
        
        }
        return mx-mn;
    }
};