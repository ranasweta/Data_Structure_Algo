class Solution {
public:
    bool doesAliceWin(string s) {
        vector<int> vowels={'a','e','i','o','u'};
        int cnt=0;
        for(char c: s){
            if(find(begin(vowels),end(vowels),c)!=vowels.end()){
                cnt++;
            }
        }
        cout<<cnt;
        if(  cnt==0){
            return false;
        }
        return true;
    }
};